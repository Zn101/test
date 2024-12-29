// noi di trien khai cac ham
#include <stdio.h>
#include "datatype.h"

void Transaction(){
	printf("ham di them danh muc san pham");
	return;
}

void mainMenu(){
	printf("**Bank management system using C**\n");
	printf("\n");
	printf("\tCHOOSE YOUR ROLE\n");
	printf("==================================\n");
	printf("[1] Admin.\n");
	printf("[2] User.\n");
	printf("[3] Exit.\n]");
	printf("=================================\n");
	return;
}

int checkLogin(const char *email, const char *password) {
    FILE *file;
    User account;
    file = fopen("User.bin", "rb");
    if (file == NULL) {
        printf("Error opening user data file.\n");
        return 0;
    }
    while (fread(&account, sizeof(User), 1, file) == 1) {
        if (strcmp(account.email, email) == 0 && strcmp(account.password, password) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void login(){
	char email[20], password[10];
	printf("**Bank management system using C**\n");
	printf("\n");
	printf("=================================\n");
	printf("Email: ");
    scanf("%s", email);
    printf("\Password: ");
    scanf("%s", password);
	printf("=================================\n");
	 if (checkLogin(email, password)) {
        printf("Login successful!\n");
    } else {
        printf("Invalid email or password.\n");
    }
	return;
}


bool doesUserIdExist(const char *userId) {
    FILE *file = fopen("user.bin", "rb");
    if (file == NULL) {
        return false;
    }
    User tempUser;
    while (fread(&tempUser, sizeof(User), 1, file)) {
        if (strcmp(tempUser.userId, userId) == 0) {
            fclose(file);
            return true;
        }
   }
}

void registerUser() {
    FILE *file = fopen("user.bin", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    User newUser;
    printf("Enter the ID: ");
    fgets(newUser.userId, sizeof(newUser.userId), stdin);
    newUser.userId[strcspn(newUser.userId, "\n")] = 0;
    printf("Enter email: ");
    fgets(newUser.email, sizeof(newUser.email), stdin);
    newUser.email[strcspn(newUser.email, "\n")] = 0;
    printf("Enter password: ");
    fgets(newUser.password, sizeof(newUser.password), stdin);
    newUser.password[strcspn(newUser.password, "\n")] = 0;
    printf("Enter your name: ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0; 
    printf("Enter date of birth: \n");
    printf("  Enter the day: ");
    scanf("%d", &newUser.dateOfBirth.day);
    printf("  Enter the month: ");
    scanf("%d", &newUser.dateOfBirth.month);
    printf("  Enter the year: ");
    scanf("%d", &newUser.dateOfBirth.year);
    printf("Enter gender (0 for male, 1 for female): ");
    scanf("%d", &newUser.gender);
    getchar();
    printf("Enter phone number: ");
    fgets(newUser.phone, sizeof(newUser.phone), stdin);
    newUser.phone[strcspn(newUser.phone, "\n")] = 0;
    if (fwrite(&newUser, sizeof(User), 1, file) != 1) {
        printf("Error writing to file.\n");
    }	 else {
        printf("User successfully registered!\n");
    }
    fclose(file);
}

void admin(){
	printf("**Student management system using C**\n");
	printf("\n");
	printf("\tMenu\n");
	printf("=================================\n");
	printf("[1] Add A New user.\n");
	printf("[2] Show All users\n");
	printf("[3] Show detail an user.\n");
	printf("[4] Lock (Unlock) an  user\n");
	printf("[5] User Guideline.\n");
	printf("[6] About Us.\n");
	printf("[0] Exit the program.\n");
	printf("=================================\n");
	return;
}

void showUser(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    User user;
    printf("|===============|======================|==============================|======================|==========|\n");
    printf("|      ID       |         NAME         |             EMAIL            |         Phone        |  Status  |\n");
    printf("|===============|======================|==============================|======================|==========|\n");

    while (fread(&user, sizeof(User), 1, file) == 1) {
        printf("| %-15s | %-20s | %-28s | %-20s | %-8s |\n", 
                user.userId, user.name, user.email, user.phone, user.lock ? "Locked" : "Unlocked");
        printf("|---------------|----------------------|------------------------------|----------------------|----------|\n");
    }

    fclose(file);
}


void lockUnlockAccount(const char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char userIdToSearch[10];
    bool newLockStatus;
    User user;
    int userFound = 0;
    printf("\t **Lock (Unlock) an user**\n");
    printf("\n");
    printf("Enter the User ID : ");
    scanf("%s", userIdToSearch);
    if (!doesUserIdExist(userIdToSearch)) {
        printf("No user was found for ID %s.\n", userIdToSearch);
        fclose(file);	
        return;
    }
    while (fread(&user, sizeof(User), 1, file) == 1) {
        if (strcmp(user.userId, userIdToSearch) == 0) {
            userFound = 1;
            printf("One user was found for ID: %s\n", user.userId);
            printf("Current lock status: %s\n", user.lock ? "Locked" : "Unlocked");
            printf("Do you want to lock the account (1 for Lock, 0 for Unlock)? ");
            scanf("%d", &newLockStatus);
            user.lock = newLockStatus;
            fseek(file, -sizeof(User), SEEK_CUR);
            fwrite(&user, sizeof(User), 1, file);
            printf("Lock status updated successfully.\n");
            break;
        }
    }
    fclose(file);
}

void end(){
	printf("========== Thank You =============\n");
	printf("======== See You Soon ============\n");
	printf("\n");
	printf("------------------------------------");
	return;
}





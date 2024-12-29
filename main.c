#include <stdio.h>
#include <stdlib.h>
#include "funtion.h"

int main() {
	int choice1, choice2, choice3;
	do{
		//mainMenu();
		//login();
		registerUser();
		showUser("User.bin");
		//lockUnlockAccount();
		printf("Your choice: ");
		scanf("%d", choice1);
	} while(choice1!=3);
	return 0;
}

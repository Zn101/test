// noi cac em di import nhung thu vien, khai bao cac struct
#include<stdbool.h>
#include<string.h>

struct Date{
	int month,day,year;
};
typedef struct Date Date;

struct Transaction{
	char transferId[50];
	char receivingId[50];
	double amount;
	char type[10];
	char message[50];
	struct Date transactionDate;
};

struct AccountInfo{
	char userId[20];
	float balance;
	bool status;
	struct Transaction transactionHistory[];
};

typedef struct {
	char userId[10];
	char email[20];
	char password[10];
	char name[20];
	struct Date dateOfBirth;
	bool gender;
	char phone[10];
	bool lock;
} User;


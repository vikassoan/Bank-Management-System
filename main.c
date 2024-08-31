#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct Customer {
    int accounterNumber;
    char name[50];
    float balance;
};

struct Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void createAccount() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Maximum number of coustomers reached.\n");
        return;
    }

    struct Customer newCustomer;
    newCustomer.accounterNumber = customerCount + 1;

    printf("Enter the name of the customer: ");
    scanf(" %[^\n]s", newCustomer.name);

    printf("Enter the initial deposit amount: ");
    scanf("%f", &newCustomer.balance);

    customers[customerCount] = newCustomer;
    customerCount++;

    printf("Account created succesfully! Your account number is %d.\n", newCustomer.accounterNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if(accountNumber > customerCount || accountNumber <= 0) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    customers[accountNumber - 1].balance += amount;

    printf("Amount deposited successfully! New balance is %.2f.\n", customers[accountNumber - 1].balance);
}

void withdeawMoney() {
    int accountNumber;
    float amount;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if (customers[accountNumber - 1].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }
    customers[accountNumber -1].balance -= amount;
    printf("Amount withdrawn successfully! New balance is %.2f.\n", customers[accountNumber - 1].balance);
}

void checkBalance() {
    int accountNumber;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if(accountNumber > customerCount || accountNumber <= 0) {
        printf("Invalid account number.\n");
        return;
    }
    printf("The balance in your account is %.2f.\n", customers[accountNumber -1 ].balance);
}

void displayCustomerDetails() {
    int accountNumber;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber > customerCount || accountNumber <= 0) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Account Number: %d\n", customers[accountNumber - 1].accounterNumber);
    printf("Name: %s\n", customers[accountNumber - 1].name);
    printf("Balance: %.2f\n", customers[accountNumber - 1].balance);
}

int main() {
    int choice;

    while(1) {
        printf("\nBank Mangement System\n");
        printf("1. Create a new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Display customer details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdeawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayCustomerDetails();
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid chooce! Please try again.\n");
        }
    }

    return 0;
}


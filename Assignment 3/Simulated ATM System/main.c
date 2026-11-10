#include <stdio.h>
#include <stdbool.h>

bool login();
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);
float borrowLoan(float balance);

int main() {
    printf("===================================\n");
    printf("      WELCOME TO THE ATM SYSTEM     \n");
    printf("===================================\n");

    if (!login()) {
        printf("\n[Access Denied] Too many incorrect attempts. Card blocked.\n");
        return 0;
    }

    float balance = 12000.00;
    int choice;

    do {
        printf("\n========= ATM MAIN MENU =========\n");
        printf("1. Balance Inquiry\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Borrow Loan (with 5%% Interest)\n");
        printf("5. Exit\n");
        printf("=================================\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                balance = borrowLoan(balance);
                break;
            case 5:
                printf("\nThank you for banking with us. Goodbye!\n");
                break;
            default:
                printf("\n[Error] Invalid choice! Please select between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

bool login() {
    int correctPin = 7070;
    int enteredPin;
    int maxAttempts = 3;

    for (int i = 1; i <= maxAttempts; i++) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == correctPin) {
            printf("Login Successful!\n");
            return true;
        } else {
            printf("Incorrect PIN. Attempts remaining: %d\n", maxAttempts - i);
        }
    }
    return false;
}

void checkBalance(float balance) {
    printf("\n--- Balance Inquiry ---\n");
    printf("Your current account balance is: Ksh %.2f\n", balance);
}

float deposit(float balance) {
    float amount;
    printf("\n--- Deposit Money ---\n");
    printf("Enter amount to deposit: Ksh ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Successfully deposited Ksh %.2f\n", amount);
        printf("New Balance: Ksh %.2f\n", balance);
    } else {
        printf("[Error] Invalid amount! Deposit amount must be positive.\n");
    }
    return balance;
}

float withdraw(float balance) {
    float amount;
    printf("\n--- Withdraw Money ---\n");
    printf("Enter amount to withdraw: Ksh ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("[Error] Invalid amount! Withdrawal amount must be positive.\n");
    } else if (amount > balance) {
        printf("[Error] Insufficient balance! Your current balance is Ksh %.2f\n", balance);
    } else {
        balance -= amount;
        printf("Successfully withdrew Ksh %.2f\n", amount);
        printf("New Balance: Ksh %.2f\n", balance);
    }
    return balance;
}

float borrowLoan(float balance) {
    float loanAmount;
    float maxLimit = 7000.00;
    float interestRate = 0.05;
    float totalRepayment;

    printf("\n--- Loan Department ---\n");
    printf("Your maximum loan limit is Ksh %.2f\n", maxLimit);
    printf("Enter loan amount you wish to borrow: Ksh ");
    scanf("%f", &loanAmount);

    if (loanAmount <= 0) {
        printf("[Error] Loan amount must be greater than zero.\n");
    } else if (loanAmount > maxLimit) {
        printf("[Error] Loan denied! Amount exceeds your maximum limit of Ksh %.2f\n", maxLimit);
    } else {
        totalRepayment = loanAmount + (loanAmount * interestRate);
        balance += loanAmount;

        printf("\nLoan Approved Successfully!\n");
        printf("-----------------------------\n");
        printf("Principal Amount   : Ksh %.2f\n", loanAmount);
        printf("Interest Rate      : 5%%\n");
        printf("Total Repayment Due: Ksh %.2f\n", totalRepayment);
        printf("-----------------------------\n");
        printf("Your account has been credited. New Balance: Ksh %.2f\n", balance);
    }
    return balance;
}

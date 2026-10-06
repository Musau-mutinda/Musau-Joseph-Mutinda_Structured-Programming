#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int correctPIN = 7070;
    int enteredPIN;
    int attempts = 3;
    int choice;
    int unlocked = 0;

    printf("=== PIN-Based Door Lock System ===\n");

    while (attempts > 0)
    {
        printf("Enter a 4-digit numerical PIN: ");
        if (scanf("%d", &enteredPIN) != 1)
        {
            printf("Invalid input. Please enter numbers only.\n");

            while (getchar() != '\n');
            continue;
        }

        if (enteredPIN >= 0 && enteredPIN < 1000)
        {
            printf("PIN is too short (must be 4 digits)\n");
        }
        else if (enteredPIN > 9999)
        {
            printf("PIN is too long (must be 4 digits)\n");
        }
        else
        {
            if (enteredPIN == correctPIN)
            {
                printf("PIN is exactly 4 digits\n");
                unlocked = 1;
                break;
            }
            else
            {
                printf("PIN is exactly 4 digits\n");
                attempts--;
                if (attempts > 0)
                {
                    printf("Incorrect PIN! You have %d attempt(s) remaining.\n", attempts);
                }
            }
        }
    }

    if (!unlocked)
    {
        printf("\nSystem locked! Wait for 5 seconds...\n");

        for (int i = 5; i >= 1; i--)
        {
            printf("%d...\n", i);
            Sleep(1000);
        }

        printf("You can try again now.\n");
        return 0;
    }

    printf("\nAccess granted. Door unlocked\n");

    do
    {
        printf("\n--- Device Menu ---\n");
        printf("1. Open Door\n");
        printf("2. Change Username\n");
        printf("3. Change PIN\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input format.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                printf("Access granted. Door unlocked\n");
                break;
            case 2:
                printf("Change username feature coming soon.\n");
                break;
            case 3:
                printf("Change PIN feature coming soon.\n");
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }while (choice != 4);

    return 0;
}

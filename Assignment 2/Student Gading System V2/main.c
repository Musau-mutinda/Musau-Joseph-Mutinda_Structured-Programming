#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i;
    char regNo[30];
    char name[50];
    int marks;
    char grade;

    printf("=== STUDENT GRADING SYSTEM (Switch-Case Version) ===\n");
    printf("Enter the number of students (N): ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input for number of students.\n");
        return 1;
    }

    for (i = 1; i <= n; i++)
    {
        printf("\n--- Entering details for Student %d ---\n", i);

        printf("Enter Registration number: ");
        scanf("%29s", regNo);

        printf("Enter Name: ");
        while (getchar() != '\n');
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Enter Marks (0-100): ");
        scanf("%d", &marks);

        if (marks < 0 || marks > 100)
        {
            printf("Error: Marks must be between 0 and 100.\n");
            continue;
        }

        switch (marks / 10)
        {
            case 10:
            case 9:
            case 8:
            case 7:
                grade = 'A';
                break;
            case 6:
                grade = 'B';
                break;
            case 5:
                grade = 'C';
                break;
            case 4:
                grade = 'D';
                break;
            default:
                grade = 'F';
                break;
        }

        printf("\n----------------------------------------\n");
        printf("           STUDENT INFORMATION          \n");
        printf("----------------------------------------\n");
        printf("Registration No: %s\n", regNo);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);

        if (marks >= 40)
        {
            printf("Status: Pass\n");
        }
        else
        {
            printf("Status: Fail\n");
        }
        printf("----------------------------------------\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i;
    char regNo[50];
    char name[50];
    int marks;
    char grade;

    printf("=== STUDENT GRADING SYSTEM (If-Else If Version) ===\n");
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
        scanf("%19s", regNo);

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

        if (marks >= 70 && marks <= 100)
        {
            grade = 'A';
        }
        else if (marks >= 60 && marks <= 69)
        {
            grade = 'B';
        }
        else if (marks >= 50 && marks <= 59)
        {
            grade = 'C';
        }
        else if (marks >= 40 && marks <= 49)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
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

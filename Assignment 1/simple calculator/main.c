#include <stdio.h>
#include <stdlib.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("choose an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);

    printf("enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
        break;
    case '/':
        if (num2 !=0)
        {
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2,result);
        }
        else
        {
            printf("error: division by zero is not allowed!\n");
        }
        break;
    case '%':
        if ((int)num2 !=0)
        {
            int remainder = (int)num1 % (int)num2;
            printf("%d %% %d = %d\n", (int)num1, (int)num2, remainder);
        }
        else
        {
            printf("error: division by zero is not allowed!\n");
        }
        break;
    default:
        printf("error: invalid operator!\n");
    }
    return 0;
}

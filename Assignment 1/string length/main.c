#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char inputString[100];

    printf("--- String Length Program ---\n");
    printf("Enter a string (like your name): ");

    if (scanf("%99s", inputString) == 1)
    {
        printf("You entered: %s\n", inputString);
        printf("Length of the string: %lu\n", strlen(inputString));
    }
    else
    {
        printf("Error reading input.\n");
    }

    return 0;
}

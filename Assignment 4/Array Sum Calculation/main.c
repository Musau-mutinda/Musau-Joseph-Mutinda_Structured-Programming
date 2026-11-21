#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
}

int calculateSum(const int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
int main(void)
{
    int arr[MAX_SIZE];
    int n;

    printf("Input the number of elements to be stored in the array : ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Input %d elements in the array :\n", n);
    readArray(arr, n);

    int total = calculateSum(arr, n);
    printf("Sum of all elements stored in the array is : %d\n", total);
    return 0;
}

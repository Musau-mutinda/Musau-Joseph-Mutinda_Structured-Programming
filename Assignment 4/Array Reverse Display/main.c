#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(const int arr[], int n) {
    printf("The values store into the array are : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printReverse(const int arr[], int n) {
    printf("The values store into the array in reverse are : ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(void)
{
    int arr[MAX_SIZE];
    int n;

    printf("Input the number of elements to store in the array : ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Input %d number of elements in the array :\n", n);
    readArray(arr, n);
    printArray(arr, n);
    printReverse(arr, n);
    return 0;
}

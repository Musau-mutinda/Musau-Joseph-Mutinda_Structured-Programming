#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void swapInts(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swapInts(&arr[i], &arr[j]);
            }
        }
    }
}

void printSorted(const int arr[], int n) {
    printf("Elements of array in sorted ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(void)
{
    int arr[MAX_SIZE];
    int n;

    printf("Input the size of array : ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Input %d elements in the array :\n", n);
    readArray(arr, n);
    sortAscending(arr, n);
    printSorted(arr, n);
    return 0;
}

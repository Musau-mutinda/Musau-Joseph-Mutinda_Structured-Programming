#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
}

int countOccurrences(const int arr[], int n, int target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

void printUniqueElements(const int arr[], int n) {
    printf("The unique elements found in the array are: ");
    for (int i = 0; i < n; i++) {
        if (countOccurrences(arr, n, arr[i]) == 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
int main(void)
{
    int arr[MAX_SIZE];
    int n;

    printf("Print all unique elements of an array:\n");
    printf("Input the number of elements to be stored in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Input %d elements in the array :\n", n);
    readArray(arr, n);
    printUniqueElements(arr, n);
    return 0;
}

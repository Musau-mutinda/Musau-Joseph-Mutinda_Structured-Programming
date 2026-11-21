#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void findMinMax(const int arr[], int n, int *minVal, int *maxVal) {
    *minVal = arr[0];
    *maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > *maxVal) {
            *maxVal = arr[i];
        }
        if (arr[i] < *minVal) {
            *minVal = arr[i];
        }
    }
}
int main(void)
{
    int arr[MAX_SIZE];
    int n, minVal, maxVal;

    printf("Input the number of elements to be stored in the array : ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Input %d elements in the array :\n", n);
    readArray(arr, n);
    findMinMax(arr, n, &minVal, &maxVal);

    printf("Maximum element is : %d\n", maxVal);
    printf("Minimum element is : %d\n", minVal);
    return 0;
}

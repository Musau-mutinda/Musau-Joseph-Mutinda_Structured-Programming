#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
}

int insertAtPosition(int arr[], int *n, int val, int pos) {
    if (*n >= MAX_SIZE || pos < 0 || pos > *n) {
        return 0;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
    return 1;
}

void printList(const char *label, const int arr[], int n) {
    printf("%s", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(void)
{
    int arr[MAX_SIZE];
    int n, val, pos;

    printf("Input the size of array : ");
    if (scanf("%d", &n) != 1 || n < 0 || n >= MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Input %d elements in the array :\n", n);
    readArray(arr, n);

    printf("Input the value to be inserted : ");
    scanf("%d", &val);

    printf("Input the Position, where the value to be inserted : ");
    scanf("%d", &pos);

    printList("The current list of the array : ", arr, n);

    if (!insertAtPosition(arr, &n, val, pos)) {
        printf("Invalid insertion position or buffer full.\n");
        return 1;
    }

    printList("After Insert the element the new list is: ", arr, n);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 4

void print2DArray(int rows, int cols, const int grid[rows][cols]) {
    printf("2D Array (%dx%d) elements:\n", rows, cols);
    for (int r = 0; r < rows; r++) {
        printf("Row %d: ", r);
        for (int c = 0; c < cols; c++) {
            printf("%4d ", grid[r][c]);
        }
        printf("\n");
    }
}
int main(void)
{
    int matrix[ROWS][COLS] = {
        { 10,  20,  30,  40},
        { 50,  60,  70,  80},
        { 90, 100, 110, 120},
        {130, 140, 150, 160},
        {170, 180, 190, 200},
        {210, 220, 230, 240}
    };

    print2DArray(ROWS, COLS, matrix);
    return 0;
}

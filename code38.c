#include <stdio.h>

int searchMatrix(int mat[][4], int r, int c, int key) {
    int i = 0, j = c - 1;

    while (i < r && j >= 0) {
        if (mat[i][j] == key) {
            printf("Element found at position (%d, %d)\n", i, j);
            return 1;
        }
        else if (mat[i][j] > key) {
            j--;   // move left
        }
        else {
            i++;   // move down
        }
    }
    return 0;
}

int main() {
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int key = 29;

    if (!searchMatrix(mat, 4, 4, key))
        printf("Element not found\n");

    return 0;
}

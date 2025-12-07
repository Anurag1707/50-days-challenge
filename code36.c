#include <stdio.h>

#define N 3   // Change size if needed (NxN matrix)

void rotate90Clockwise(int a[N][N]) {
    int i, j, temp;

    // Step 1: Transpose of matrix
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (i = 0; i < N; i++) {
        for (j = 0; j < N / 2; j++) {
            temp = a[i][j];
            a[i][j] = a[i][N - j - 1];
            a[i][N - j - 1] = temp;
        }
    }
}

void printMatrix(int a[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main() {
    int a[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    printMatrix(a);

    rotate90Clockwise(a);

    printf("\nRotated Matrix (90° Clockwise):\n");
    printMatrix(a);

    return 0;
}

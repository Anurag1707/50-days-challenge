#include <stdio.h>

void booleanMatrix(int a[][3], int r, int c) {
    int rowFlag = 0, colFlag = 0;

    // Check first row
    for(int j = 0; j < c; j++)
        if(a[0][j] == 1)
            rowFlag = 1;

    // Check first column
    for(int i = 0; i < r; i++)
        if(a[i][0] == 1)
            colFlag = 1;

    // Mark rows and columns
    for(int i = 1; i < r; i++) {
        for(int j = 1; j < c; j++) {
            if(a[i][j] == 1) {
                a[i][0] = 1;
                a[0][j] = 1;
            }
        }
    }

    // Update matrix
    for(int i = 1; i < r; i++) {
        for(int j = 1; j < c; j++) {
            if(a[i][0] == 1 || a[0][j] == 1)
                a[i][j] = 1;
        }
    }

    // Update first row
    if(rowFlag) {
        for(int j = 0; j < c; j++)
            a[0][j] = 1;
    }

    // Update first column
    if(colFlag) {
        for(int i = 0; i < r; i++)
            a[i][0] = 1;
    }
}

int main() {
    int a[3][3] = {
        {0,0,1},
        {0,0,0},
        {0,0,0}
    };

    booleanMatrix(a, 3, 3);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}

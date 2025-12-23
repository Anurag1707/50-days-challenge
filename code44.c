#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Boundary Traversal:\n");

    // Top row
    for(int j = 0; j < c; j++)
        printf("%d ", a[0][j]);

    // Right column
    for(int i = 1; i < r; i++)
        printf("%d ", a[i][c - 1]);

    // Bottom row (if more than 1 row)
    if(r > 1) {
        for(int j = c - 2; j >= 0; j--)
            printf("%d ", a[r - 1][j]);
    }

    // Left column (if more than 1 column)
    if(c > 1) {
        for(int i = r - 2; i > 0; i--)
            printf("%d ", a[i][0]);
    }

    return 0;
}

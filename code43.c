#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[10][10];

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Snake Pattern:\n");
    for(i = 0; i < r; i++) {
        if(i % 2 == 0) {   // even row
            for(j = 0; j < c; j++) {
                printf("%d ", a[i][j]);
            }
        } else {          // odd row
            for(j = c - 1; j >= 0; j--) {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}


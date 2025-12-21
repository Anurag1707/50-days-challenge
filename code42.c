#include <stdio.h>

int main() {
    int n, i;
    int a[10][10];

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Main Diagonal: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i][i]);

    printf("\nSecondary Diagonal: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i][n - i - 1]);

    return 0;
}

#include <stdio.h>

void spiralPrint(int a[][100], int r, int c)
{
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    int i;

    while (top <= bottom && left <= right)
    {
        // Left to Right
        for (i = left; i <= right; i++)
            printf("%d ", a[top][i]);
        top++;

        // Top to Bottom
        for (i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // Right to Left
        if (top <= bottom)
        {
            for (i = right; i >= left; i--)
                printf("%d ", a[bottom][i]);
            bottom--;
        }

        // Bottom to Top
        if (left <= right)
        {
            for (i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }
}

int main()
{
    int r, c, i, j;
    int a[100][100];

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("Spiral traversal:\n");
    spiralPrint(a, r, c);

    return 0;
}


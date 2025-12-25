#include <stdio.h>

int searchMatrix(int matrix[][100], int r, int c, int target) {
    int low = 0, high = r * c - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / c;
        int col = mid % c;

        if (matrix[row][col] == target)
            return 1;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int main() {
    int r, c, target;
    int matrix[100][100];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    if (searchMatrix(matrix, r, c, target))
        printf("Element FOUND\n");
    else
        printf("Element NOT FOUND\n");

    return 0;
}

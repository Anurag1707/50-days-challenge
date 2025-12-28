#include <stdio.h>

int countSmallerEqual(int mat[][3], int R, int C, int x) {
    int count = 0;

    for (int i = 0; i < R; i++) {
        int l = 0, h = C - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (mat[i][mid] <= x)
                l = mid + 1;
            else
                h = mid - 1;
        }
        count += l;   // number of elements <= x in row i
    }
    return count;
}

int findMedian(int mat[][3], int R, int C) {
    int min = mat[0][0], max = mat[0][C - 1];

    for (int i = 1; i < R; i++) {
        if (mat[i][0] < min)
            min = mat[i][0];
        if (mat[i][C - 1] > max)
            max = mat[i][C - 1];
    }

    int desired = (R * C + 1) / 2;

    while (min < max) {
        int mid = (min + max) / 2;
        int count = countSmallerEqual(mat, R, C, mid);

        if (count < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main() {
    int mat[3][3] = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    printf("Median is: %d\n", findMedian(mat, 3, 3));
    return 0;
}

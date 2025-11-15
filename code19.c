#include <stdio.h>

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);   // ceiling(gap/2)
}

void merge(int arr1[], int n, int arr2[], int m) {
    int gap = n + m;
    
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {

        int i, j;

        // Compare elements inside arr1
        for (i = 0; i + gap < n; i++) {
            if (arr1[i] > arr1[i + gap]) {
                int temp = arr1[i];
                arr1[i] = arr1[i + gap];
                arr1[i + gap] = temp;
            }
        }

        // Compare elements between arr1 and arr2
        for (j = (gap > n) ? (gap - n) : 0, i = (gap > n) ? n : gap;
             i < n && j < m;
             i++, j++) {
            
            if (arr1[i] > arr2[j]) {
                int temp = arr1[i];
                arr1[i] = arr2[j];
                arr2[j] = temp;
            }
        }

        // Compare elements inside arr2
        if (j < m) {
            for (j = 0; j + gap < m; j++) {
                if (arr2[j] > arr2[j + gap]) {
                    int temp = arr2[j];
                    arr2[j] = arr2[j + gap];
                    arr2[j + gap] = temp;
                }
            }
        }
    }
}

int main() {
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    merge(arr1, n, arr2, m);

    printf("Array 1: ");
    for (int i = 0; i < n; i++) printf("%d ", arr1[i]);
    printf("\nArray 2: ");
    for (int i = 0; i < m; i++) printf("%d ", arr2[i]);
}

#include <stdio.h>

void rearrange(int arr[], int n) {
    int temp[n];
    int i, pos = 0, neg = 0;

    // Separate positives and negatives
    for (i = 0; i < n; i++) {
        if (arr[i] >= 0)
            temp[pos++] = arr[i];
    }

    for (i = 0; i < n; i++) {
        if (arr[i] < 0)
            temp[pos + neg++] = arr[i];
    }

    int pIndex = 0, nIndex = pos;
    i = 0;

    // Alternate positive and negative elements
    while (pIndex < pos && nIndex < n) {
        arr[i++] = temp[pIndex++];
        arr[i++] = temp[nIndex++];
    }

    // Copy remaining positives
    while (pIndex < pos)
        arr[i++] = temp[pIndex++];

    // Copy remaining negatives
    while (nIndex < n)
        arr[i++] = temp[nIndex++];
}

int main() {
    int arr[] = {2, 3, -4, -1, 6, -9};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);

    printf("Rearranged array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

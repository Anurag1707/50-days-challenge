#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Partition process (similar to quicksort)
    j = 0;  // Index for next negative number
    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            // Swap negative number to the front
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    printf("Array after rearranging:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

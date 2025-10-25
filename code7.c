#include <stdio.h>

int main() {
    int n, i, last;

    // Input size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Store last element
    last = arr[n - 1];

    // Shift all elements one position to right
    for(i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Put last element at first position
    arr[0] = last;

    // Display rotated array
    printf("Array after one cyclic rotation: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

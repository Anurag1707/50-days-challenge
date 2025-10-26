#include <stdio.h>
#include <stdbool.h>

// Function to check if array is sorted and rotated
bool isSortedAndRotated(int arr[], int n) {
    int countAsc = 0, countDesc = 0;

    // Count places where order is violated (for ascending)
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[(i + 1) % n])
            countAsc++;
    }

    // Count places where order is violated (for descending)
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[(i + 1) % n])
            countDesc++;
    }

    // If only one place violates ascending order -> sorted and rotated ascending
    // OR only one place violates descending order -> sorted and rotated descending
    if (countAsc == 1 || countDesc == 1)
        return true;

    return false;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isSortedAndRotated(arr, n))
        printf("Array is sorted and rotated.\n");
    else
        printf("Array is NOT sorted and rotated.\n");

    return 0;
}

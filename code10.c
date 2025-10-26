#include <stdio.h>

void findLeaders(int arr[], int n) {
    int maxFromRight = arr[n - 1];  // Rightmost element is always a leader
    printf("Leaders in the array: %d ", maxFromRight);

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            printf("%d ", maxFromRight);
        }
    }

    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    findLeaders(arr, n);

    return 0;
}

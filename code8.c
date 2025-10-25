#include <stdio.h>

int main() {
    int n, i;

    // Input array size
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = arr[0];
    int current_sum = arr[0];

    // Kadane’s Algorithm
    for (i = 1; i < n; i++) {
        // Either extend the current subarray or start new from arr[i]
        if (current_sum + arr[i] > arr[i])
            current_sum = current_sum + arr[i];
        else
            current_sum = arr[i];

        // Update max_sum if needed
        if (current_sum > max_sum)
            max_sum = current_sum;
    }

    printf("Maximum Subarray Sum = %d\n", max_sum);

    return 0;
}

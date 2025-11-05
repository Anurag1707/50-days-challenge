#include <stdio.h>

void subarrayWithGivenSum(int arr[], int n, int sum) {
    int current_sum = arr[0];
    int start = 0;

    for (int end = 1; end <= n; end++) {
        // Shrink the window as long as current_sum > sum
        while (current_sum > sum && start < end - 1) {
            current_sum -= arr[start];
            start++;
        }

        // Check if we found the sum
        if (current_sum == sum) {
            printf("Subarray found between indexes %d and %d\n", start, end - 1);
            return;
        }

        // Add next element to window
        if (end < n)
            current_sum += arr[end];
    }

    printf("No subarray found with the given sum.\n");
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 33;

    subarrayWithGivenSum(arr, n, sum);
    return 0;
}


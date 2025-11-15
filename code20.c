#include <stdio.h>

int maxProduct(int arr[], int n) {
    int max_ending = arr[n-1];
    int min_ending = arr[n-1];
    int max_product = arr[n-1];

    for (int i = n-2; i >= 0; i--) {

        int a = arr[i];

        // If negative, swap max_ending and min_ending
        if (a < 0) {
            int temp = max_ending;
            max_ending = min_ending;
            min_ending = temp;
        }

        // Update max/min ending at current index
        max_ending = (a > a * max_ending) ? a : a * max_ending;
        min_ending = (a < a * min_ending) ? a : a * min_ending;

        // Update global max product
        if (max_ending > max_product)
            max_product = max_ending;
    }

    return max_product;
}

int main() {
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum Product Subarray = %d\n", maxProduct(arr, n));
    return 0;
}

#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n - 1];
    printf("Enter %d numbers (from 1 to %d, with one missing):\n", n - 1, n);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &arr[i]);

    int total = n * (n + 1) / 2;  // Sum of 1 to n
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
        sum += arr[i];

    int missing = total - sum;

    printf("Missing number is: %d\n", missing);
    return 0;
}

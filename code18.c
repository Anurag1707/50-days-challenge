#include <stdio.h>
#include <stdlib.h>

long long trap(int* height, int n) {
    if (n <= 2) return 0;
    int l = 0, r = n - 1;
    int left_max = 0, right_max = 0;
    long long water = 0;

    while (l <= r) {
        if (height[l] <= height[r]) {
            if (height[l] >= left_max) {
                left_max = height[l];
            } else {
                water += (long long)(left_max - height[l]);
            }
            l++;
        } else {
            if (height[r] >= right_max) {
                right_max = height[r];
            } else {
                water += (long long)(right_max - height[r]);
            }
            r--;
        }
    }
    return water;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) {
        printf("0\n");
        return 0;
    }
    int *height = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) scanf("%d", &height[i]);

    long long result = trap(height, n);
    printf("%lld\n", result);

    free(height);
    return 0;
}

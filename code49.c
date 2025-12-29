#include <stdio.h>

#define MAX 100

// Function to find max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Largest Rectangle in Histogram
int largestRectangleArea(int heights[], int n) {
    int stack[MAX];
    int top = -1;
    int maxArea = 0;
    int i = 0;

    while (i < n) {
        if (top == -1 || heights[stack[top]] <= heights[i]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = max(maxArea, h * width);
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        maxArea = max(maxArea, h * width);
    }

    return maxArea;
}

// Maximum rectangle of 1s in binary matrix
int maxRectangle(int matrix[][MAX], int r, int c) {
    int height[MAX] = {0};
    int maxArea = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }
        maxArea = max(maxArea, largestRectangleArea(height, c));
    }
    return maxArea;
}

// Driver Code
int main() {
    int matrix[4][MAX] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int r = 4, c = 4;

    printf("Maximum rectangle of 1s area = %d\n", maxRectangle(matrix, r, c));

    return 0;
}

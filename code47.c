#include <stdio.h>

#define ROWS 5
#define COLS 5

void dfs(int grid[ROWS][COLS], int r, int c) {
    // Check boundaries and water/visited
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0)
        return;

    // Mark current cell as visited
    grid[r][c] = 0;

    // Explore neighbors (up, down, left, right)
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int countIslands(int grid[ROWS][COLS]) {
    int count = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main() {
    int grid[ROWS][COLS] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    printf("Number of islands: %d\n", countIslands(grid));
    return 0;
}

#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char arr[][100], int n) {
    static char prefix[100];
    strcpy(prefix, arr[0]);  // start with first string

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (prefix[j] && arr[i][j] && prefix[j] == arr[i][j])
            j++;

        prefix[j] = '\0';  // shorten prefix

        if (prefix[0] == '\0')
            return prefix;  // no common prefix at all
    }

    return prefix;
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char arr[n][100];
    printf("Enter strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    char *result = longestCommonPrefix(arr, n);
    if (result[0] == '\0')
        printf("No common prefix\n");
    else
        printf("Longest Common Prefix: %s\n", result);

    return 0;
}

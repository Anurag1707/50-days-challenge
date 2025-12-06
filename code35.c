#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(const char *s1, const char *s2) {
    int i = 0, j = 0;

    // Traverse both strings
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] == s2[j]) {
            i++;  // move in s1
        }
        j++;      // always move in s2
    }

    // If we've matched all characters in s1, it's a subsequence
    return s1[i] == '\0';
}

int main() {
    char s1[] = "ace";
    char s2[] = "abcde";

    if (isSubsequence(s1, s2))
        printf("\"%s\" is a subsequence of \"%s\"\n", s1, s2);
    else
        printf("\"%s\" is NOT a subsequence of \"%s\"\n", s1, s2);

    return 0;
}

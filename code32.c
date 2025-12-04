#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];  // To store last index of every character
    for (int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0;  // Sliding window start

    for (int i = 0; s[i] != '\0'; i++) {
        // If character already seen and is inside the current window
        if (lastIndex[(unsigned char)s[i]] >= start) {
            start = lastIndex[(unsigned char)s[i]] + 1;
        }

        // Update last seen index
        lastIndex[(unsigned char)s[i]] = i;

        // Update max length
        int currLen = i - start + 1;
        if (currLen > maxLen)
            maxLen = currLen;
    }

    return maxLen;
}

int main() {
    char s[200];
    printf("enter \n");
    scanf("%s", s);

    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}

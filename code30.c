#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(char *s) {
    int l = 0;
    int r = strlen(s) - 1;

    while (l < r) {
        if (s[l] != s[r]) {
            // Try removing left OR right one character
            return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }
        l++;
        r--;
    }
    return true;  
}

int main() {
    char s[100];

    printf("Enter string: ");
    scanf("%s", s);

    if (validPalindrome(s))
        printf("YES, Valid Palindrome (after removing at most one char)\n");
    else
        printf("NO, Not possible\n");

    return 0;
}

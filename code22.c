#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j;

    printf("Enter a string: ");
    gets(str);

    i = 0;
    j = strlen(str) - 1;

    while(i < j) {
        if(str[i] != str[j]) {
            printf("Not Palindrome");
            return 0;
        }
        i++;
        j--;
    }

    printf("Palindrome");
    return 0;
}

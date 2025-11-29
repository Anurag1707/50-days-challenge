#include <stdio.h>
#include <string.h>

int isAnagram(char str1[], char str2[]) {
    int count[256] = {0};
    int i;

    if (strlen(str1) != strlen(str2))
        return 0;

    for (i = 0; str1[i] && str2[i]; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    for (i = 0; i < 256; i++) {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if (isAnagram(str1, str2))
        printf("Strings are anagrams\n");
    else
        printf("Strings are NOT anagrams\n");

    return 0;
}

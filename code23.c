#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int index = 0;
    int visited[256] = {0};  // For all ASCII characters

    for (int i = 0; str[i] != '\0'; i++) {
        if (!visited[(unsigned char)str[i]]) {   // If character not seen
            visited[(unsigned char)str[i]] = 1;  // Mark seen
            str[index++] = str[i];               // Keep this char
        }
    }
    str[index] = '\0';   // Terminate string
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);
    return 0;
}


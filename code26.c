#include <stdio.h>
#include <string.h>

void countAndSay(int n) {
    char current[5000] = "1";
    char next[5000];

    for (int k = 1; k < n; k++) {
        int i = 0, idx = 0;

        while (current[i] != '\0') {
            char ch = current[i];
            int count = 0;

            while (current[i] == ch) {
                count++;
                i++;
            }

            // Convert count to char and save
            next[idx++] = count + '0';
            next[idx++] = ch;
        }

        next[idx] = '\0';

        // Copy next → current
        strcpy(current, next);
    }

    printf("%s", current);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    countAndSay(n);

    return 0;
}

#include <stdio.h>

int myAtoi(char *s) {
    int i = 0, sign = 1, result = 0;

    // Skip leading spaces
    while (s[i] == ' ')
        i++;

    // Check sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    else if (s[i] == '+') {
        i++;
    }

    // Convert digits to integer
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return sign * result;
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int value = myAtoi(str);
    printf("Converted integer = %d\n", value);

    return 0;
}

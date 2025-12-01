#include <stdio.h>

char* my_strstr(const char *haystack, const char *needle) {
    if (!*needle)      // empty needle → return full string
        return (char*)haystack;

    for (const char *h = haystack; *h; h++) {
        const char *p = h;
        const char *q = needle;

        while (*p && *q && (*p == *q)) {
            p++;
            q++;
        }

        if (!*q)       // matched full needle
            return (char*)h;
    }

    return NULL;       // no match
}

int main() {
    char str[] = "hello world";
    char sub[] = "world";

    char *pos = my_strstr(str, sub);

    if (pos)
        printf("Found at index: %ld\n", pos - str);
    else
        printf("Not found\n");

    return 0;
}

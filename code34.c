#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isRotation(const char *s1, const char *s2) {
    // If lengths differ, cannot be rotation
    if (strlen(s1) != strlen(s2))
        return false;

    // Make a buffer big enough for s1 + s1
    char doubled[512];  // adjust size as needed
    snprintf(doubled, sizeof(doubled), "%s%s", s1, s1);

    // Check if s2 is a substring of doubled
    return strstr(doubled, s2) != NULL;
}

int main() {
    char s1[] = "ABCD";
    char s2[] = "CDAB";

    if (isRotation(s1, s2))
        printf("%s is a rotation of %s\n", s2, s1);
    else
        printf("%s is NOT a rotation of %s\n", s2, s1);

    return 0;
}

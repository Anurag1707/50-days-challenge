#include <stdio.h>
#include <string.h>

/* Compress in-place and return new length.
   chars: array of characters (not necessarily null-terminated)
   charsSize: number of elements in chars
*/
int compress(char *chars, int charsSize) {
    if (charsSize == 0) return 0;

    int read = 0;   // reads through the input
    int write = 0;  // writes compressed output

    while (read < charsSize) {
        char curr = chars[read];
        int count = 0;

        // count occurrences of curr
        while (read < charsSize && chars[read] == curr) {
            read++;
            count++;
        }

        // write the character
        chars[write++] = curr;

        // if count > 1, write its digits
        if (count > 1) {
            // convert count to string
            // using a small buffer (max digits for int are safe here)
            char buf[12];
            int len = sprintf(buf, "%d", count); // len >= 1
            for (int i = 0; i < len; ++i) {
                chars[write++] = buf[i];
            }
        }
    }

    return write;
}

/* Example usage */
int main(void) {
    // Example 1: ["a","a","b","b","c","c","c"] -> ["a","2","b","2","c","3"], length = 6
    char arr1[] = {'a','a','b','b','c','c','c'};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int newlen1 = compress(arr1, n1);

    printf("New length: %d\n", newlen1);
    printf("Compressed chars: ");
    for (int i = 0; i < newlen1; ++i) putchar(arr1[i]);
    putchar('\n');

    // Example 2: ["a"] -> ["a"], length = 1
    char arr2[] = {'a'};
    int n2 = 1;
    int newlen2 = compress(arr2, n2);
    printf("New length: %d\n", newlen2);
    printf("Compressed chars: ");
    for (int i = 0; i < newlen2; ++i) putchar(arr2[i]);
    putchar('\n');

    // Example 3: long run -> ["a","12"] for 12 'a's
    char arr3[] = {'a','a','a','a','a','a','a','a','a','a','a','a'}; // 12 a's
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int newlen3 = compress(arr3, n3);
    printf("New length: %d\n", newlen3);
    printf("Compressed chars: ");
    for (int i = 0; i < newlen3; ++i) putchar(arr3[i]);
    putchar('\n');

    return 0;
}

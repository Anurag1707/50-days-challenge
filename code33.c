#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* helper: sort characters of a string in-place using qsort */
int cmp_char(const void *a, const void *b) {
    return (*(const char*)a) - (*(const char*)b);
}

char *sorted_key(const char *s) {
    size_t n = strlen(s);
    char *k = malloc(n + 1);
    if (!k) { perror("malloc"); exit(1); }
    memcpy(k, s, n + 1);
    qsort(k, n, sizeof(char), cmp_char);
    return k;
}

/* struct to hold original string and its sorted key */
typedef struct {
    char *orig;   /* pointer to original string (owned by caller or duplicated) */
    char *key;    /* allocated sorted key */
} Item;

/* compare items by key for qsort */
int cmp_item(const void *a, const void *b) {
    const Item *ia = (const Item*)a;
    const Item *ib = (const Item*)b;
    return strcmp(ia->key, ib->key);
}

/* Example grouping function: prints groups to stdout */
void group_anagrams(char **arr, int n) {
    if (n <= 0) return;

    Item *items = malloc(sizeof(Item) * n);
    if (!items) { perror("malloc"); exit(1); }

    /* build items */
    for (int i = 0; i < n; ++i) {
        items[i].orig = arr[i];
        items[i].key = sorted_key(arr[i]);
    }

    /* sort by key */
    qsort(items, n, sizeof(Item), cmp_item);

    /* iterate and print groups */
    int start = 0;
    while (start < n) {
        int end = start + 1;
        while (end < n && strcmp(items[start].key, items[end].key) == 0) end++;

        /* print group from start..end-1 */
        printf("[ ");
        for (int i = start; i < end; ++i) {
            printf("\"%s\"%s", items[i].orig, (i+1<end) ? ", " : " ");
        }
        printf("]\n");

        start = end;
    }

    /* free keys */
    for (int i = 0; i < n; ++i) free(items[i].key);
    free(items);
}

/* quick demo */
int main(void) {
    char *arr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Grouped anagrams:\n");
    group_anagrams(arr, n);

    return 0;
}

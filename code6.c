#include <stdio.h>

int main() {
    int a[100], b[100], unionArr[200], interArr[100];
    int n1, n2, i, j, k = 0, l = 0;
    int found;

    // Input for first array
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array:\n");
    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    // Input for second array
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array:\n");
    for (i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    // ---- UNION ----
    // Copy all elements of first array
    for (i = 0; i < n1; i++)
        unionArr[k++] = a[i];

    // Add elements of second array only if not already in unionArr
    for (i = 0; i < n2; i++) {
        found = 0;
        for (j = 0; j < n1; j++) {
            if (b[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            unionArr[k++] = b[i];
    }

    // ---- INTERSECTION ----
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (a[i] == b[j]) {
                // check to avoid duplicates in intersection
                int duplicate = 0;
                for (int m = 0; m < l; m++) {
                    if (interArr[m] == a[i])
                        duplicate = 1;
                }
                if (!duplicate)
                    interArr[l++] = a[i];
            }
        }
    }

    // Display Union
    printf("\nUnion of arrays: ");
    for (i = 0; i < k; i++)
        printf("%d ", unionArr[i]);

    // Display Intersection
    printf("\nIntersection of arrays: ");
    for (i = 0; i < l; i++)
        printf("%d ", interArr[i]);

    return 0;
}

#include <stdio.h>

int main() {
    int a[100], b[100];
    int n1, n2, i = 0, j = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements (sorted): ", n1);
    for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter %d elements (sorted): ", n2);
    for(i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    printf("Intersection elements: ");
    i = 0; j = 0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j])
            i++;
        else if(b[j] < a[i])
            j++;
        else { // both equal
            printf("%d ", a[i]);
            i++;
            j++;
        }
    }

    return 0;
}

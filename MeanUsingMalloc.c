#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,i,p,sum = 0,*a;

    printf("\n Enter limit: ");
    scanf("%d", &n);

    // Check if n is a valid number
    if (n <= 0) {
        printf("Invalid input. The limit should be a positive integer.\n");
        return 1;
    }

    a = (int*)malloc(n * sizeof(int));

    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\n Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p);
        a[i] = p;
        sum += a[i];
    }

    printf("\n Elements are:");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);

    // Calculate the mean (average)
    if (n > 0) {
        double mean = (double)sum / n;
        printf("\n Mean: %.2lf\n", mean);
    } else {
        printf("\n Mean: N/A (Division by zero)\n");
    }

    free(a);
    return 0;
}


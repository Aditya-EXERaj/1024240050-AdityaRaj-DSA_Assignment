#include <stdio.h>
int main() {
    int a[10][10], b[10][10], c[10][10], i, j, k, m, n, p, q;
    printf("Enter rows and cols of first matrix: ");
    scanf("%d%d", &m, &n);
    printf("Enter rows and cols of second matrix: ");
    scanf("%d%d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    printf("Enter first matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter second matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

    printf("Resultant Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
int main() {
    int a[10][10], m, n, i, j, rowSum, colSum;
    printf("Enter rows and cols: ");
    scanf("%d%d", &m, &n);

    printf("Enter matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < m; i++) {
        rowSum = 0;
        for (j = 0; j < n; j++)
            rowSum += a[i][j];
        printf("Sum of row %d = %d\n", i, rowSum);
    }

    for (j = 0; j < n; j++) {
        colSum = 0;
        for (i = 0; i < m; i++)
            colSum += a[i][j];
        printf("Sum of col %d = %d\n", j, colSum);
    }

    return 0;
}

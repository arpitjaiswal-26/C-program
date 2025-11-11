#include <stdio.h>

int main() {
    int m, n, i, j;
    int sum = 0;

    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    int matrix[m][n];

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for(i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of diagonal elements = %d\n", sum);

    return 0;
}

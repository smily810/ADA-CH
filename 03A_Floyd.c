#include <stdio.h>
#define MAX 10

int main() {
    int a[MAX][MAX], n, i, j, k;

    printf("\nEnter the n value : ");
    scanf("%d", &n);

    printf("\nEnter the graph data : \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];

    printf("\nShortest path matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}

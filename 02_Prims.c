#include <stdio.h>
#define INF 999
#define MAX 20

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int i, j, source, edges = 1, min_cost = 0;

    printf("Enter the no. of nodes:");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the root node:");
    scanf("%d", &source);
    visited[source] = 1;

    printf("\nMinimum cost spanning tree is\n");
    while (edges < n) {
        int min = INF, a = 0, b = 0;

        for (i = 1; i <= n; i++)
            if (visited[i])
                for (j = 1; j <= n; j++)
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }

        printf("\nEdge %d\t(%d->%d)=%d\n", edges++, a, b, min);
        visited[b] = 1;
        min_cost += min;
    }

    printf("\nMinimum cost=%d\n", min_cost);
    return 0;
}

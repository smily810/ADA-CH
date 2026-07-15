#include <stdio.h>
#define MAX 20

int set[MAX], x[MAX], n, target, found = 0;

void subset(int i, int sum) {
    int j;

    if (sum == target) {
        found = 1;
        for (j = 0; j < i; j++)
            if (x[j])
                printf("%d ", set[j]);
        printf("\n");
        return;
    }

    if (i == n || sum > target)
        return;

    x[i] = 1;
    subset(i + 1, sum + set[i]);

    x[i] = 0;
    subset(i + 1, sum);
}

int main() {
    int i;

    printf("\nEnter the n value:");
    scanf("%d", &n);

    printf("\nEnter the set in increasing order:");
    for (i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("\nEnter the max subset value:");
    scanf("%d", &target);

    subset(0, 0);

    if (!found)
        printf("\nNo subset possible");

    return 0;
}

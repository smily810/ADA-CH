#include <stdio.h>

int main() {
    float weight[50], profit[50], ratio[50], capacity, total = 0, temp;
    int n, i, j;

    printf("Enter the number of items :");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d] :\n", i);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter the capacity of knapsack :\n");
    scanf("%f", &capacity);

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (ratio[i] < ratio[j]) {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }

    for (i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            total += profit[i];
            capacity -= weight[i];
        } else {
            total += ratio[i] * capacity;
            capacity = 0;
        }
    }

    printf("Knapsack problems using Greedy Algorithm:\n");
    printf("\nThe maximum value is :%f\n", total);

    return 0;
}

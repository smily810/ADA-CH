#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int knapsack(int w[], int p[], int n, int M)
{
    if (M == 0)
        return 0;
    if (n == 0)
        return 0;
    if (w[n - 1] > M)
        return knapsack(w, p, n - 1, M);
    return max(knapsack(w, p, n - 1, M),
               p[n - 1] + knapsack(w, p, n - 1, M - w[n - 1]));
}
void main()
{
    int i, n;
    int M;    
    int w[10];  
    int p[10]; 

    printf("Enter the no. of items:\n");
    scanf("%d", &n);

    printf("Enter the weight and price of all items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &w[i], &p[i]);
    }

    printf("Enter the capacity of knapsack\n");
    scanf("%d", &M);

    printf("The maximum value of items that can be put into knapsack is = %d\n",
           knapsack(w, p, n, M));
}

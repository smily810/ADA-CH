#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selsort(int a[], int n)
{
    int i, j, small, pos, temp;

    for (j = 0; j < n - 1; j++)
    {
        small = a[j];
        pos = j;

        for (i = j + 1; i < n; i++)
        {
            if (a[i] < small)
            {
                small = a[i];
                pos = i;
            }
        }

        temp = a[j];
        a[j] = a[pos];
        a[pos] = temp;
    }
}

int main(void)
{
    int i, n, k;
    int a[10000];
    clock_t start, end;
    double duration;

    printf("Enter n value (try 1000 or more): ");
    scanf("%d", &n);

    srand(time(NULL));

    for (i = 0; i < n; i++)
        a[i] = rand() % n;

    start = clock();

    for (k = 0; k < 100; k++)
        selsort(a, n);

    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime taken for n = %d is: %f seconds", n, duration);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000
#define REPEAT 100    // repeat to amplify time

int array[MAX], temp[MAX];

void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= high)
        temp[k++] = array[j++];

    for (i = low; i <= high; i++)
        array[i] = temp[i];
}

void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main(void)
{
    int n, i, k;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements (try 1000+): ");
    scanf("%d", &n);

    srand(time(NULL));

    for (i = 0; i < n; i++)
        array[i] = rand() % n;

    start = clock();

    for (k = 0; k < REPEAT; k++)
        merge_sort(0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for n = %d is: %f seconds\n", n, time_taken);

    return 0;
}

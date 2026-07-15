#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000
#define REPEAT 100    // repeat count to amplify time

int partition(long int arr[], int low, int high)
{
    long int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            long int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    long int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void qs(long int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        qs(arr, low, mid - 1);
        qs(arr, mid + 1, high);
    }
}

int main(void)
{
    int n, i, k;
    long int a[MAX];
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements (try 1000+): ");
    scanf("%d", &n);

    srand(time(NULL));

    for (i = 0; i < n; i++)
        a[i] = rand() % n;

    start = clock();

    for (k = 0; k < REPEAT; k++)
        qs(a, 0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for n = %d is: %f seconds\n", n, time_taken);

    return 0;
}

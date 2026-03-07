#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    // Select a random pivot & move it to the end
    int pivotIndex = low + rand() % (high - low + 1);
    swap(&arr[pivotIndex], &arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Driver Code
int main()
{
    srand(time(NULL)); // Seed RNG once

    int arr[] = {4,1,3,9,7,5,8,2,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Array after sorting: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

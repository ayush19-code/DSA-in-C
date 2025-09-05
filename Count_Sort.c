#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void countsort(int A[], int n)
{
    int i, j;
    int max = maximum(A, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printf("Array before sorting:\n");
    printArray(A, n);
    countsort(A, 7);
    printf("Array After sorting:\n");
    printArray(A, n);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

void printarr(int *A,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


void selection_sort(int *A,int n){
    int indexofmin, temp;
    printf("running selection sort\n");
    for (int i = 0; i < n-1; i++)
    {
        indexofmin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[indexofmin]>A[j]){
                indexofmin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexofmin];
        A[indexofmin] = temp;
    }
    
}

int main(){
    int A[] = {3,1,5,4,9,7};
    int n = 6;

    printf("Array before sorting:\n");
    printarr(A,n);
    selection_sort(A,n);
    printf("Array after sorting:\n");
    printarr(A,n);
}
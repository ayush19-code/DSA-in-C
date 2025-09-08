#include<stdio.h>
#include<stdlib.h>

void printarr(int *A,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


void insertion_sort(int *A,int n){
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1] =A[j];
            j--;
        }
        A[j+1] = key;
    }
    
}

int main(){
    int A[] = {3,1,5,4,9,7};
    int n = 6;
    
    printf("Array before sorting:\n");
    printarr(A,n);
    insertion_sort(A,n);
    printf("Array after sorting:\n");
    printarr(A,n);
}


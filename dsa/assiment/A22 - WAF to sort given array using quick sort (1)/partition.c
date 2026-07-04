#include "main.h"

/* Function to partition the array */
int partition(int *arr, int first, int last)
{
    int pivot = first;
    int  p = first+1,q=last;
    
    while(p <= q)
    {
        if(arr[p] <= arr[pivot])
        {
            p++;
        }
        
        if(arr[q] > arr[pivot])
        {
            q--;
        }
        
        if(p<q)
        {
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }
    
    int temp = arr[q];
    arr[q] = arr[pivot];
    arr[pivot] = temp;
    
    return q;
    
}

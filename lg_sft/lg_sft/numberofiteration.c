#include <stdio.h>
#include <stdbool.h>
int noiterationsort(int arr[], int n)
{
    int iterations = 0;
    for(int i = 0; i < n - 1; i ++)
    {
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                bool swapped = true;
            }
            iterations++;
            if(!swapped)
            break;
        }
    }
    return iterations;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",noiterationsort(arr, n));
}
#include<stdio.h>
int main()
{
    int size;
    scanf("%d",&size);
    int arr[size];

    for(int i=0;i<size;i++)
    {
        scanf("%d",&rr[i]);
    }

    int lar = arr[0];
    int small = arr[0];

    for(int i=1;i,size;i++)
    {
        if(arr[i]>lar)
        {
            lar = arr[i];
        }
        if(arr[i]<small)
        {
            small = arr[i];
        }
    }
    int diff = lar - small
    printf("%d",diff);
}
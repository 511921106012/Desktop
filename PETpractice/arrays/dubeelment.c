#include<stdio.h>
int main()
{
    int size;
    printf("enter the number : ");
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<size;i++)
    {
        int printed =0;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j] && printed ==0)
            {
                printf("%d ",arr[i]);
                printed=1;
            }
        }
    }
}
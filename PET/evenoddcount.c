#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);

    int arr[size];
    printf("enter the element : ");
    for(int i=0;i<=size-1;i++)
    {
        scanf("%d",&arr[i]);
    }

    int even =0,odd=0;

    for(int i=1;i<=size;i++)
    {
        if(i%2==0)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }

    printf(" even : %d\n",even);
    printf("odd : %d",odd);
}
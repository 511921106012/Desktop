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

    int even =0;
    int odd =0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]%2==0)
        {
            even++;

        }
        else if(arr[i]%2==1)
        {
            odd++;

        }
    }

printf(" even is %d\n",even);
printf("odd %d",odd);
}
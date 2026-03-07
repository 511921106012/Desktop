#include<stdio.h>
int main()
{
    int size;
    printf("enter the number : ");
    scanf("%d",&size);

    int arr[size];
    for(int i=0 ; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int falg=0


    for(int i=0; i<size; i++)
    {
        for(int k=0;k<i;k++)
        {

        if(arr[i]==arr[k])
        {
            falg=1;
            break;
        
        }\
    }

    if(falg==1)
    {
        continue;
    }
        int count =0;
        for(int j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }

             printf("%d -  %d",arr[i],count);
        }
    }



}
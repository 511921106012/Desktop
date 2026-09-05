#include<stdio.h>
int main()
{
    int  size;
    printf("enter the size : ");
    scanf("%d",&size);
    int arr[size];

    int target;
    printf("enter the element : ");


    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the target : ");
    scanf("%d",&target);
    int flag =0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==target)
        {
            printf(" the target is %d the index is %d",target,i);
            flag=1;
            break;

        }
    }

    if(flag==0)
    {
        printf("the element is not there");
    }

    
}
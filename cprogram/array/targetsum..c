#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);
    

    if(size<=0)
    {
        printf("invalid input : ");
        return 0;
    }
    int arr[size];



    printf("enter the elements ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    int target ;
    printf("enter the target : ");
    scanf("%d",&target);


    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+arr[j]==target)
            {
                printf("%d %d  =%d",i,j,target);
                return 0;
            }
        }
    }
    printf("no pair found ");
    return 0;


}
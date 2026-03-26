#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);
    if(size ==0)
        {
            printf("nothing is there");
            return 0;
        }
        else if(size <  0 )
        {
            printf("invalid size  : ");
            return 0;
        }
    

    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    
   


int temp = arr[0];

    for(int i=0;i<size;i++)
    {
       
        

        if(arr[i] > temp)
        {
            temp = arr[i];
        }


    }

    printf("%d ",temp);
}

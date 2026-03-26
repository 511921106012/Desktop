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

    printf("enter the elements : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    

int k=1;
    for(int i=1;i<size;i++)
    {
        
            if(arr[i]!=arr[i-1])
            {
                arr[k++]=arr[i];

               

                
                
            }
        
    }


     printf("%d, ",k);

     for(int i=0;i<k;i++)
     {
        printf("%d ",arr[i]);
     }

 

}
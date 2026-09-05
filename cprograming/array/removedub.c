#include<stdio.h>
int main()
{
    int size,i,j;
    printf("enter the size : ");
    scanf("%d",&size);

    int arr[size];
    printf("enter the element : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    int sort[size];
    int size1=1;
    sort[0]=arr[0];

    for( i=1;i<size;i++)
    {
        for(j=0;j<size1;j++)
        {

            if(arr[i]==sort[j])
            {
                break;
            }
        }
                


        

        if(j==size1)
        {
            sort[size1]=arr[i];
            size1++;
        }
    
    }


     for(int i=0;i<size1;i++)
     {
        printf("%d ",sort[i]);
     }
}
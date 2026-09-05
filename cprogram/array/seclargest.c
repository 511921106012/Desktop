#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);
    int arr[size];

    printf("enter the element : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    int seclar =-1;
    int largest = arr[0];


    for(int i=0;i<size;i++)
    {
        if(largest <arr[i])
        {
            seclar = largest;
            largest = arr[i];

            
            

        }
        else if(arr[i]>seclar && arr[i]!= largest)
        {
            seclar = arr[i];
        }

       

    }
    
    
 printf("the  largest element is %d\n",largest);
        printf("the sec largest element is %d",seclar);

  
}
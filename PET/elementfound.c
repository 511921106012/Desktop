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

    
    int n;
    printf("enter the found number : ");
    scanf("%d",&n);

    int found =0;


     for(int i=0;i<=size-1;i++)
     {
        if(n == arr[i])
        {
            found++;
        }
     }

     if(found ==1 )
     {
        printf("the element is found :");
     }
     else
     {
        printf("the element is not found : ");
     }


}
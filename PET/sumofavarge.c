#include<stdio.h>
int main()
{
    int size,sum=1;
    printf("enter the size :");
    scanf("%d",&size);

    float  avarage;
   // avarage = float(sum)/size;

    int arr[size];
    printf("enter the element : ");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&arr[i]);
    }


    for(int i=1;i<=size;i++)
    {
         sum = sum +i;

    }
     avarage = (float)sum/size;
    printf("\n%d \n",sum);
    printf("%f",avarage);

    
}
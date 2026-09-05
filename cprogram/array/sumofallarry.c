#include<stdio.h>
int main()
{
    int size;
    printf("enter the element : ");
    scanf("%d",&size);
    int arr[size];

    printf("enter the element : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

int sum =0;
    for(int i=0;i<size;i++)
    {
        sum = sum+arr[i];

    }

    float avarage = (float)sum/size;
    printf(" sum = %d \n avarage = %f",sum ,avarage);
}
#include<stdio.h>
int main()
{
    int size;
    printf("enter the number : ");
    scanf("%d",&size);

    int arr[size];
    int arr1[size];

     printf("enter the element : ");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&arr[i]);
    }

  printf("the array element is : ");
  for(int i=1;i<=size;i++)
  {
    printf("%d ",arr[i]);
    arr1[i]=arr[i];
  }
  printf("\n");

  printf("the array 1 element is : ");
  for(int i=1;i<=size;i++)
  {
    printf("%d ",arr1[i]);
  }


}
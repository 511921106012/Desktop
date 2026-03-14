#include<stdio.h>
int main(){
    int n;
    printf("enter the size : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements : ");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]!=i+1)
        {
           printf("%d",i+1);
            return 0;
        }
    }
  //  printf("%d\n",n+1);
    return 0;

}
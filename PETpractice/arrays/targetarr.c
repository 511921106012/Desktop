#include<stdio.h>
void sum(int *arr ,int size,int target,int *index1,int   * index2)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if((arr[i]+arr[j])==target)
            {
                *index1 =i;
                *index2 =j;
                return;
            }
        }
    }
}
int main()
{
    int size;
    printf("enter the size ");
    scanf("%d",&size);
    int arr[size];

    for(int i =0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("enter the target number : ");
    int target;
    scanf("%d",&target);

    int index1 =-1, index2 =-1;

    sum(arr,size,target,&index1,&index2);
    if(index1!=-1)
    printf("the two number of target is %d = %d %d",target,index1,index2);
}
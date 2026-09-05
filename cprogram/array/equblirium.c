#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    if(n <=0  || n >= 10000)
    {
        printf("-1\n");
        return 0;
    }

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    } 

    long long total =0,left =0;

    for(int i=0;i<n;i++) 
    {
        total = total + arr[i];
    }


    for(int i=0;i<n;i++)
    {
        total = total - arr[i];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        if(left == total )
        {
            printf("%d\n",i);
            return 0;
        }

        left = left +arr[i];
    }
    printf("-1\n");
    return 0;
}
#include<stdio.h>
int main()
{
    int found =0;
    
    int arr[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int target;
    printf("enter the target : ");
    scanf("%d",&target);


    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(j+1 <5)
            {
            if(arr[i][j]+arr[i][j+1] == target)
            {
                printf("%d + %d = %d\n",arr[i][j],arr[i][j+1],target);
                found=1;
            }
            }

            if(i+1 < 5)
            {
                if(arr[i][j] + arr[i+1][j] == target)
                {
                    printf("%d + %d = %d\n",arr[i][j],arr[i+1][j],target);
                    found =1;
                }
            }
            if(i+1<5 && j+1<5)
            {
                if(arr[i][j]+ arr[i+1][j+1] == target)
                {
                    printf("%d + %d = %d\n",arr[i][j],arr[i+1][j+1],target);
                    found =1;
                }
            }

            

            




        }
    }

        if(found == 0 )
        {
            printf("no found is there");
        }
    

    return 0;
}
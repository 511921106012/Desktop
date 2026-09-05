#include<stdio.h>
int main()

{
    int size1, size2,i,j,flag;
    printf("enter the siz1 : ");
    scanf("%d",&size1);

    printf("enter the size2 : ");
    scanf("%d",&size2);

    int arr1[size1];
    int arr2[size2];

    int  inside[size2];

    printf("enter the arr1 element : ");
    for( i=0;i<size1;i++)
    {
        scanf("%d",&arr1[i]);

    }

    printf("enter the size2 : ");
    for(j=0;j<size2;j++)
    {
        scanf("%d",&arr2[j]);

    }

    for(j=0;j<size2;j++)
    {
        inside[i]=0;
    }


int found ;

    for(int i=0;i<size1;i++)
    {
          found=0;
        for(j=0;j<size2;j++)
        {
            if(arr1[i]==arr2[j] && inside[j]==0 )
            {
                inside[j]=1;
                found=1;
                break;
            }
        }

      
    }

     if(found ==0)
       {
        printf("not equal : ");
       }
       else
       {
         printf("the element are equal  : ");
        
       }

  //  printf("the element are equal  : ");

}
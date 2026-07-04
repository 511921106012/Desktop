#include <stdio.h>
#include <stdlib.h>

void magic_square(int **arr,int n)
{
    int row = n/2,col=n-1,limit =n*n;
    
    for(int num = 1;num<=limit;)
    {
        if(row == -1 && col == n)
        {
            row = 0;
            col = col-2;
        }
        else
        {
            if(row<0)
            row = n-1;
            if(col == n)
            col = 0;
        }
        
        if(arr[row][col])
        {
            row++;
            col = col-2;
            continue;
        }
        else
        {
            arr[row][col] = num;
            num++;
        }

       row--;
       col++;

    }   
}

int main()
{    int size;
     printf("Enter size of an array->\n");
     scanf("%d",&size);
     if(size <= 0 || size%2 == 0)
     {
         printf("Invalid Input\n");
         return 0;
     }
     
      int**arr;
      
      arr =(int**)calloc(size,sizeof(int*));
      for(int i=0;i<size;i++)
      {
         arr[i] = (int*)calloc(size,sizeof(int));
      }
      
      magic_square(arr,size);
      
      for(int i=0;i<size;i++)
      {
        for(int j=0;j<size;j++)
        {
          printf("%d ",arr[i][j]);
        }
        printf("\n");
      }
      
      for(int i=0;i<size;i++)
      {
          free(arr[i]);
      }
      
     free(arr);
     
     return 0;
}
/*#include <stdio.h>
#include <stdlib.h>*/

//left rotate ------------//

/*int main()
{
    int size,rotate;
    printf("Enter the array size->\n");
    scanf("%d",&size);
    if(size <= 0)
    {
       printf("Invalid input\n");
       return 0;
    }
    printf("Enter how many time want to rotate->\n");
    scanf("%d",&rotate);
    
    if(rotate < 0)
    {
       printf("Invalid input\n");
       return 0;
    }
    
    int *arr = calloc(size,sizeof(int));

    printf("Enter the array elements->\n");
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    
     int i,j,temp;

    for(i=0;i<rotate;i++)
    {
        temp = arr[0];

        for(j =0;j<size-1;j++)
        {
           arr[j] = arr[j+1];
        }

        arr[size-1] = temp;
    } 

    printf("After rotate->\n");
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
    printf("\n");

    free(arr);

    return 0;
}*/

//right rotate --------------//

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size,rotate;
    printf("Enter the array size->\n");
    scanf("%d",&size);
    if(size <= 0)
    {
       printf("Invalid input\n");
       return 0;
    }
    printf("Enter how many time want to rotate->\n");
    scanf("%d",&rotate);
    
    if(rotate < 0)
    {
       printf("Invalid input\n");
       return 0;
    }
    
    int *arr = calloc(size,sizeof(int));

    printf("Enter the array elements->\n");
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    
     int i,j,temp;

    for(i=0;i<rotate;i++)
    {
        temp = arr[size-1];

        for(j =size-1;j>0;j--)
        {
           arr[j] = arr[j-1];
        }

        arr[0] = temp;
    } 

    printf("After rotate->\n");
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
    printf("\n");

    free(arr);

    return 0;
}*/

//90 clockwise---------------//

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
   int row,col;
   printf("Enter the row and col for the array->\n");
   scanf("%d %d",&row,&col); 

  int **arr;
  arr = calloc(row*col,sizeof(int));
  for(int i=0;i<col;i++)
  {
    arr[i] = calloc(col,sizeof(int));
  }

  printf("Enter the array elements->\n");
  for(int i =0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
       scanf("%d",&arr[i][j]);
    }
  }

  printf("After rotate->\n");
  for(int i =0;i<col;i++)
  {
    for(int j=row-1;j>=0;j--)
    {
       printf("%d ",arr[j][i]);
    }
    printf("\n");
  }  

  return 0;
}*/

//90 anit _clockwise---------------//

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int row,col;
   printf("Enter the row and col for the array->\n");
   scanf("%d %d",&row,&col); 

  int **arr;
  arr = calloc(row*col,sizeof(int));
  for(int i=0;i<col;i++)
  {
    arr[i] = calloc(col,sizeof(int));
  }

  printf("Enter the array elements->\n");
  for(int i =0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
       scanf("%d",&arr[i][j]);
    }
  }

  printf("After rotate->\n");
  for(int i =col-1;i>=0;i--)
  {
    for(int j=0;j<row;j++)
    {
       printf("%d ",arr[j][i]);
    }
    printf("\n");
  }  

  return 0;
}

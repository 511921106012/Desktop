#include <stdio.h>

void spiral_print(int row,int col,int arr[row][col])
{
    int k=0,m=0;
    int last_row = row-1,last_col = col-1;
  
 while(k <=last_row && m <= last_col)
 { 
    for(int i=m;i<=last_col;i++)
    {
       printf("%d ",arr[k][i]);
    }
    k++;

    for(int j=k;j<=last_row;j++)
    {
       printf("%d ",arr[j][last_col]);
    }
    last_col--;

    if(k<= last_row)
    {
    for(int i=last_col;i>=m;i--)
    {
       printf("%d ",arr[last_row][i]);
    }
    last_row--; 
    }

    if(m  <= last_col)
    {
    for(int j=last_row;j>=k;j--)
    {
        printf("%d ",arr[j][m]);
    }
    m++;
   }

}

}
int main()
{
  
  int row,col;
  printf("Enter the row and col for array->\n");
  scanf("%d %d",&row,&col);
  int arr[row][col];
  //scan the elements
  printf("Enter the array elements->\n");
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
       scanf("%d",&arr[i][j]);
    }
  }

  spiral_print(row,col,arr);
    printf("\n");
    return 0;  
}*/


/*#include<stdio.h>

/*int main()
{
    char str[20];
    scanf("%4s",str);

    printf("%s",str);}*/

    #include <stdio.h>
// Assume base address of "GeeksQuiz" to be 1000
int main()
{
   printf(5 + "GeeksQuiz");
   return 0;
}

#include <stdio.h>

void wave_form(int row,int col,int arr[row][col])
{
    
  for(int i=0;i<row;i++)
    {  
       if(i %2 == 0)
       {	    
         for(int j=0;j<col;j++)
         printf("%d ",arr[i][j]);
       }
       else
       {
	 for(int j = col-1;j>=0;j--)
	  printf("%d ",arr[i][j]);	 
       }
     }
}


int main()
{
    int row,col;
    printf("Enter the row and column for the array-> ");
    scanf("%d %d",&row,&col);

    if(row <= 0 || col <= 0)
    {
       printf("Invalid Input\n");
       return 0;
    }
    
	int arr[row][col];
         
        printf("Enter the array elements->\n");
          
   for(int i=0;i<row;i++)
	 {
            for(int j=0;j<col;j++)
	    {
               scanf("%d",&arr[i][j]);
	    }

	 }	
    
        printf("Wave output:\n");
        wave_form(row,col,arr);

    return 0;

}

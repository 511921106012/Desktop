#include <stdio.h>

int main()
{
    
   int arr[9][9]={
	   {1,2,3,4,5,6,7,8,9},
	   {4,5,6,7,8,9,1,2,3},
	   {7,8,9,1,2,3,4,5,6},
     {2,3,4,5,6,7,8,9,1},
	   {5,6,7,8,9,1,2,3,4},
	   {8,9,1,2,3,4,5,6,7},
	   {3,4,2,6,7,8,9,1,2},
	   {6,7,8,9,1,2,3,4,5},
	   {9,1,2,3,4,5,6,7,8},
           };

   if(check_row(arr) == 0 && check_column(arr) == 0 && cube_check(arr) == 0)
   printf("Sudoku is Valid...\n");
   else
   printf("sudoku is not valid...\n");

 return 0;   
   	   
}

int check_row(int arr[9][9])
{
 int i,j,k;

 int c[10] = {0}; 
 
 for(i = 0;i<9;i++)
 {
   for(j=0;j<9;j++)
   {
      c[arr[i][j]]++;
   }
 for(k = 1;k<=9;k++)
 {
    if(c[k]!=1)
      return 0;	    
 }
  
 for(k=1;k<=9;k++)
  c[k] = 0;
}

return 1;  

}




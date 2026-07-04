#include <stdio.h>
#include <stdlib.h>

int main()
{
   int size;
   printf("Enter the array size->\n");
   scanf("%d",&size);

   if(size <=0 || size%2 == 0)
   {
      printf("Invalid Input\b");
      return 0;
   }
   
   int**arr = calloc(size,sizeof(int*));
   for(int i=0;i<size;i++)
   {
      arr[i] = calloc(size,sizeof(int));
   }

   printf("Enter the elements->\n");
   for(int i=0;i<size;i++)
   {
     for(int j=0;j<size;j++)
     {
      scanf("%d",&arr[i][j]);
     }
   }

   int magicnumber = 0;
   for(int i=0;i<size;i++)
   {
      magicnumber+=arr[0][i];
   }

   //row check
   for(int i=1;i<size;i++)
   {
       int rowcheck = 0;
       for(int j=0;j<size;j++)
       {
          rowcheck += arr[i][j];       
       }

       if(rowcheck != magicnumber)
       {
         printf("NOT a magic square\n");
         return 0;
       }
   }
   
   //col check
   for(int i=0;i<size;i++)
   {
      int colcheck = 0;
    for(int j=0;j<size;j++)
    {
        colcheck+=arr[j][i];  
    }

    if(colcheck != magicnumber)
    {
       printf("NOT a magic square\n");
       return 0;
    }
   }

   //dig1 check
  
    int diag1= 0;
   for(int i=0;i<size;i++)
   {
     diag1 += arr[i][i];
   }

   int diag2 = 0;
   for(int i=0;i<size;i++)
   {
      diag2 += arr[i][size-i-1];
   }

   if(diag1 != magicnumber)
   {
     printf("NOT a magic square\n");
     return 0;
   }
   
   if(diag2 != magicnumber)
   {
     printf("NOT a magic square\n");
     return 0;
   }

   printf("it is the magic square\n");
   
  for(int i=0;i<size;i++)
  {
     free(arr[i]);
  }
    free(arr);

   return 0;

}
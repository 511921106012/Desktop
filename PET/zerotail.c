#include <stdio.h>
#include <stdlib.h>

void shift_zero(int *arr,int size,int*result)
{    
     int count = 0;

     for(int i=0;i<size;i++)
     {
        if(arr[i]!=0)
        {
           result[count] = arr[i];
           count++;
        }
     }

     for(count;count<size;count++)
     {
         result[count] = 0;
     }

}

int main()
{
     int size;
     printf("Enter the array size->\n");
     scanf("%d",&size);

     int *arr = calloc(size,sizeof(int));
     int * result = calloc(size,sizeof(int));

     printf("Enter the array elements->\n");
     for(int i =0;i<size;i++)
     {
        scanf("%d",&arr[i]);
     }

      void (*ptr)(int*,int,int*) = shift_zero;
      ptr(arr,size,result);

      printf("After shifting ->\n");
      for(int i=0;i<size;i++)
       printf("%d ",result[i]);
       
       printf("\n");
       
      
      return 0;

}

#include <stdio.h>
#include <stdlib.h>

int isprime(int num)
{
    if(num <= 1)
    return 0;

    for(int i=2;i*i<=num;i++)
    {
       if(num%i == 0) 
       return 0;
    }

    return 1;
}

int nextprime(int num)
{
   num++;
   while(!isprime(num))
   {
     num++;
   }
    return num;
}
int main()
{
    int size;
    printf("Enter array size->\n");
    scanf("%d",&size);

    int *arr = calloc(size,sizeof(int));

    printf("Enter Array elements->\n");
    for(int i=0;i<size;i++)
     scanf("%d",&arr[i]);

    for(int i=0;i<size;i++)
    {
       if(!isprime(arr[i]))
       {
         arr[i] = nextprime(arr[i]);
       }  
    } 

    printf("Array elements->\n");
    for(int i=0;i<size;i++)
     printf("%d ",arr[i]);
     
     printf("\n");
     
     free(arr);

     return 0;
}
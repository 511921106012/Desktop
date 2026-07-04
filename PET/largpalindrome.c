#include <stdio.h>
#include <stdlib.h>

int palidrome(int num)
{
    int temp = num,rev = 0;

    while(temp != 0)
    {
       int rem = temp%10;
       rev = rev*10+rem;
       temp/=10;
    }

    if(rev == num)
    {
        return 1;
    }

    return 0;
}



int main()
{
    int size;
    printf("Enter the size to an array->\n");
    scanf("%d",&size);

    int*arr = calloc(size,sizeof(int));

    printf("Enter the array elements->\n");
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    
    int lar=arr[0];

    for(int i=0;i<size;i++)
    {
      if(palidrome(arr[i])&& arr[i] > lar)
      {
          lar = arr[i];
      }
    }


    printf("The largest palindrome is->%d\n",lar);

return 0;

}
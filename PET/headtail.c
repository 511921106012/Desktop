#include <stdio.h>
#include <stdlib.h>

void shift_zero(int*read,int size,int *write)
{
     int count = size;

     for(int i=size-1;i>=0;i--)
     {
        if(read[i]!=0)
        {
           write[count-1] = read[i];
           count--;
        }
     }

    for(int i= count-1;i>=0;i--)
    {
       write[i] = 0;
    }

}

int main()
{
    int size;
    printf("Enter the array size->\n");
    scanf("%d",&size);

    int*read= calloc(size,sizeof(int));
    int*write= calloc(size,sizeof(int));

    printf("Enter the array elements->\n");
    for(int i =0;i<size;i++)
    scanf("%d",&read[i]);

    void (*ptr)(int*,int,int*) = shift_zero;
    ptr(read,size,write);

    printf("After shift->\n");
    for(int i=0;i<size;i++)
    printf("%d ",write[i]);

    printf("\n");

    return 0;
}
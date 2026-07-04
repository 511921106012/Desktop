#include <stdio.h>

void tower_of_hanio(int disk,char src,char aux,char dest)
{
    if(disk == 1)
    {
       printf("Move disk %d from %c to %C\n",disk,src,dest); 
       return;
    }

     tower_of_hanio(disk-1,src,dest,aux);

     printf("Move disk %d from %c to %c\n",disk,src,dest);

     tower_of_hanio(disk-1,aux,src,dest);

}

int main()
{
    int disk;
    printf("Enter the disk->\n");
    scanf("%d",&disk);
 

   tower_of_hanio(disk,'A','B','C');

   return 0;    
}

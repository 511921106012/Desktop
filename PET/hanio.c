#include <stdio.h>

void tower_of_hanio(int disk,char a,char b,char c)
{
    if(disk == 1)
    {
       printf("Move disk %d from %c to %c\n",disk,a,c); 
       return;
    }

     tower_of_hanio(disk-1,a,c,b);

     printf("Move disk %d from %c to %c\n",disk,a,c);

     tower_of_hanio(disk-1,b,a,c);

}

int main()
{
    int disk;
    printf("Enter the disk->\n");
    scanf("%d",&disk);
 

   tower_of_hanio(disk,'A','B','C');

   return 0;    
}

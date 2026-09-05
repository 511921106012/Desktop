#include<stdio.h>
void swap (int *n,int *m)
{

    int temp = *n;
    *n = *m;
    *m = temp;
}
int main()
{
    int n,m;
    printf("enter the number : ");
    scanf("%d %d",&n,&m);
    printf("%d %d",n,m);
    printf("\n after swap the value is \n");
    swap(&n,&m);
    printf("%d %d\n",n,m);
    return 0;

}
#include<stdio.h>
int main()
{
    struct student {
        int id ;
        char str[100];
        char str2[100];




    };


    struct student s1;

    printf("enter the id : ");
    scanf("%d",&s1.id);

    getchar();

    printf("enter the name : ");
    fgets(s1.str,50,stdin);

    printf("enter the address : ");
    fgets(s1.str2,50,stdin);


    printf("----  student data is -------\n");
    printf(" id : %d\n",s1.id);
    printf("the name is :%s",s1.str);
    printf("address is %s",s1.str2);
}
#include<stdio.h>
int main()
{
    int *ptr1 ;
    char * ptr2;
    float *ptr3;
    double * ptr4;

    printf("%zu",sizeof(ptr1));
    printf("%zu",sizeof(ptr2));
    printf("%zu",sizeof(ptr3));
    printf("%zu",sizeof(ptr4));
}
#include <stdio.h>
#include <stdlib.h>
void allocate(int **p)
{
    *p = malloc(sizeof(int));
    **p = 100;
}

int main()
{
    int *ptr = NULL;
    allocate(&ptr);
    printf("%d\n", *ptr);
}
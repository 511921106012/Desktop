#include "hash.h"

void create_HT(hash_t *arr, int size)
{
    int i = 0;
    
    while(i<size)
    {
        arr[i].index = i;
        arr[i].value = -1;
        arr[i].link = NULL;
        i++;
    }
}

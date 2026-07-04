#include"hash.h"

int destroy_HT(hash_t *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i].value == -1)
        {
            continue;
        }
        else
        {
           hash_t * temp = arr[i].link;
           hash_t * next = NULL;
           
           while(temp != NULL)
           {
               next = temp->link;
               free(temp);
               temp = next;
           }
           
           arr[i].value = -1;
           arr[i].link = NULL;
        }
    }
    
    return SUCCESS;
}
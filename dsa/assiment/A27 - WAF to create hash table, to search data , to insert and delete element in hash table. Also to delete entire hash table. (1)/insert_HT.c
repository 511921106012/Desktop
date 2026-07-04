#include"hash.h"

int insert_HT(hash_t *arr, int element, int size)
{
    
    int index = element % size;
    
    if(arr[index].value == -1)
    {
        arr[index].value = element;
        return SUCCESS;
    }
    
    hash_t * new1 = malloc(sizeof(hash_t));
    
    if(new1 == NULL)
    {
        return FAILURE;
    }
    
    new1->value = element;
    new1->link = NULL;
    
    if(arr[index].link == NULL)
    {
        arr[index].link = new1;
        return SUCCESS;
    }
    else
    {
        hash_t * temp1 = arr[index].link;
        
        while(temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        
        temp1->link = new1;
        
        return SUCCESS;
        
    }
    
    
}
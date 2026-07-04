#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist*new1 = malloc(sizeof(Dlist));
    
    if(new1 == NULL)
    {
      return FAILURE;
    }
    
    new1->data = data;
    
    if(*head == NULL)
    {
        *head = new1;
        *tail = new1;
        new1->prev = NULL;
        new1->next = NULL;
        
        return SUCCESS;
    }
    
    (*tail)->next = new1;
    new1->prev = *tail;
    new1->next = NULL;
    *tail = new1;
    
     return SUCCESS;
}
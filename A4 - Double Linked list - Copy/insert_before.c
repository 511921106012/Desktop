#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    Dlist *temp = *head;
    
    if(temp->data == gdata)
    {
        Dlist *new1 = malloc(sizeof(Dlist));
        
        if(new1 == NULL)
        {
            return FAILURE;
        }
        
        new1->data = ndata;
        new1->prev = NULL;
        new1->next = *head;
        
        (*head)->prev = new1;
        *head = new1;
        
        return SUCCESS;
    }
    
    while(temp != NULL)
    {
        if(temp->data == gdata)
        {
            Dlist *new1 = malloc(sizeof(Dlist));
            
            if(new1 == NULL)
            {
                return FAILURE;
            }
            
            new1->data = ndata;
            new1->prev = temp->prev;
            new1->next = temp;
            
            temp->prev->next = new1;
            temp->prev = new1;
            
            return SUCCESS;
        }
        
        temp = temp->next;
    }
    
    return DATA_NOT_FOUND;
}
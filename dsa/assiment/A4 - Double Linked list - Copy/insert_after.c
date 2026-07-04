#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    Dlist *temp = *head;
    
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
            new1->prev = temp;
            new1->next = temp->next;
            
            
            if(temp->next != NULL)
            {
             temp->next->prev = new1;
            }
            else
            {
              *tail = new1;
            }
            
            temp->next = new1;
            
            return SUCCESS;
        }
        
        temp = temp->next;
    }
    
    return DATA_NOT_FOUND;
}
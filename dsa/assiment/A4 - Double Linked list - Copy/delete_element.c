#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    Dlist *temp = *head;
    
    if(temp->data == data)
    {
        if(*head == *tail)
        {
            free(temp);
            *head = NULL;
            *tail = NULL;
            return SUCCESS;
        }
        
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
        
        return SUCCESS;
    }
    
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            if(temp->next == NULL)
            {
                *tail = temp->prev;
                (*tail)->next = NULL;
                free(temp);
                return SUCCESS;
            }
            
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            
            return SUCCESS;
        }
        
        temp = temp->next;
    }
    
    return DATA_NOT_FOUND;
}
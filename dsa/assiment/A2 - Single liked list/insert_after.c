#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    Slist*temp = *head; 
    
    while(temp != NULL)
    {
        if(temp->data == g_data)
        {
            Slist*new1 = malloc(sizeof(Slist));
            
            if(new1 == NULL)
            {
               return FAILURE;
            }
            
            new1->data = ndata;
            new1->link = temp->link;
            temp->link = new1;
            return SUCCESS;
        }
        
           temp = temp->link;
    }
    
    return DATA_NOT_FOUND;    
}
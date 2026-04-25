#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{
    
    
    Slist *new1 = malloc(sizeof(Slist));
    
    if(new1 == NULL)
    {
       return FAILURE;
    }
    
    new1->data = data;
    new1->link = NULL;
    
    if(*head == NULL)
    {
        *head = new1;
        return SUCCESS;
    }
    
    Slist*temp = *head;
    
    while(temp->link != NULL)
    {
       temp = temp->link;
    }
    
    temp->link = new1;
    
    return SUCCESS;
    
}
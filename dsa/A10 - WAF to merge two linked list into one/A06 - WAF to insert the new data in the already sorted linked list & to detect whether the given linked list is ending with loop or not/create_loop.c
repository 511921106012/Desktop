#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
    Slist *join=NULL;
    
    
    if(*head== NULL)
    {
     
     return LIST_EMPTY;   
    }
    
    Slist *temp=*head;
    
    while(temp->link != NULL)
    {
        if(temp->data==data)
        {
            
            join=temp;
        }
        temp=temp->link;
    }
    
    if(join==NULL)
    {
    return  DATA_NOT_FOUND;
    }
    else
    {
        temp->link=join;
        return SUCCESS;
    }
    

}
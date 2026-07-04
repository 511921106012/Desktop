#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{ 
    Slist *new=malloc(sizeof(Slist));
    
    if(new==NULL)
    {
        return FAILURE;
    }
    new->data=data;
    new->link=NULL;
    
    
    Slist *temp=*head;
    Slist *prev=NULL;
    
    while(temp != NULL)
    {
        if(temp->data > new->data)
        {
             new->link=temp;
            break;
            
        }
        prev=temp;
        temp=temp->link;
    }
    if(prev==NULL)
            {
                *head=new;
                return SUCCESS;
                
            }
    prev->link=new;
    return SUCCESS;
    

} 
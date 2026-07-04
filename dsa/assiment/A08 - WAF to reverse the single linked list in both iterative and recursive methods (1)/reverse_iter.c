#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head) 
{ 
    if(*head==NULL)
    {
        return LIST_EMPTY;
    }
    
    Slist *temp=*head;
    Slist *prev=NULL;
    Slist *next=NULL;
    while(temp!=NULL)
    {
        if(temp==*head && temp->link==NULL)
        {
            return SUCCESS;
        }
        next=temp->link;
        temp->link=prev;
        if(next==NULL)
        {
            *head=temp;
        }
        prev=temp;
        temp=next;
    }
    return SUCCESS;
} 
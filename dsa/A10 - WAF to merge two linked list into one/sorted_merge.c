#include "sll.h"

int sorted_merge( Slist **head1, Slist **head2)
{
    if(*head1==NULL)
    {
        if(*head2==NULL)
        {
            return LIST_EMPTY;
        }
        else
        {
            *head1=*head2;
            sort(head1);
            return SUCCESS;
        }  
    }
    if(*head2==NULL)
    {
        if(*head1==NULL)
        {
            return LIST_EMPTY;
        }
        else
        {
            sort(head1);
            return SUCCESS;
        }  
    }
    Slist *temp=*head1;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=*head2;
    *head2=NULL;
    sort(head1);
    return SUCCESS;
}
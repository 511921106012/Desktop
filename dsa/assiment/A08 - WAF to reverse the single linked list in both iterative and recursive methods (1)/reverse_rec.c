#include "sll.h"

int reverse_recursion(Slist ** head)
{
    if (*head == NULL || (*head)->link==NULL)
    {
        if(*head!=NULL && (*head)->link==NULL)
        {
            return SUCCESS;
        }
        return LIST_EMPTY;
    }

    Slist *temp = *head;
    Slist *rest = (*head)->link;

    reverse_recursion(&rest);

    (*head)->link->link = *head;  
    (*head)->link = NULL;         

    *head = rest;     
}
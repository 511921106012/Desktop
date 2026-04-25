#include "sll.h"

int sl_delete_last(Slist **head)
{
     if(*head == NULL)
     {
        return FAILURE;
     }
     
     Slist*temp = *head;
     
     if(temp->link == NULL)
     {
         free(temp);
         *head = NULL;
         
         return SUCCESS;
     }
     
     while(temp->link->link != NULL)
     {
         temp = temp->link;
     }
     
     free(temp->link);
     temp->link = NULL;
     
     return SUCCESS;
     
}
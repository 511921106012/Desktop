#include "sll.h"

int sl_delete_first(Slist **head)
{

 if(*head == NULL)
 {
    return FAILURE;
 }
 
 Slist*temp;
 
 temp = *head;
 *head = (*head)->link;
 free(temp);
 
 return SUCCESS;

}
#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
   if(*head == NULL)
   {
     return FAILURE;
   }
   
   Slist*temp = *head;
   Slist*prev = NULL;
   
   if(temp->data == data)
   {
       *head = temp->link;
       free(temp);
       
        return SUCCESS;
   }
   
   while(temp != NULL)
   {
       if(temp->data == data)
       {
           prev->link = temp->link;
           free(temp);
           return SUCCESS;
       }
       
       prev = temp;
       temp = temp->link;
       
   }
   
    return DATA_NOT_FOUND;
}
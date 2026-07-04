#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
   if(*head == NULL)
   {
       return LIST_EMPTY;
   }
   
   Slist*temp = *head;
   Slist *prev = NULL;
   
   if(temp->data == g_data)
   {
       Slist *new1 = malloc(sizeof(Slist));
  
       if(new1 == NULL)
       {
          return FAILURE;
       }
       
       new1->data = ndata;
       new1->link = *head;
       *head = new1;
       
       return SUCCESS;
   }
   
   while(temp != NULL)
   {
       if(temp->data == g_data)
       {
           Slist *new1 = malloc(sizeof(Slist));
           
           if(new1 == NULL)
           {
               return FAILURE;
           }
           
           new1->data = ndata;
           new1->link = temp;
           prev->link = new1;
           
           return SUCCESS;
       }
       
       prev = temp;
       temp = temp->link;
   }
   
   return DATA_NOT_FOUND;
}
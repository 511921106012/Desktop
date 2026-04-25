#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
  
   if(n <= 0)
   {
       return POSITION_NOT_FOUND; 
   }

   if(*head == NULL)
   {
       if(n == 1)
       {
           Slist *new1 = malloc(sizeof(Slist));
           
           if(new1 == NULL)
           {
               return FAILURE;
           }

           new1->data = data;
           new1->link = NULL;
           *head = new1;

           return SUCCESS;
       }
       else
       {
           return LIST_EMPTY;
       }
   }

   Slist *new1 = malloc(sizeof(Slist));
   
   if(new1 == NULL)
   {
       return FAILURE;
   }
   
   new1->data = data;

   if(n == 1)
   {
       new1->link = *head;
       *head = new1;
       return SUCCESS;
   }

   Slist *temp = *head;
   int count = 1;

   while(temp != NULL && count < n - 1)
   {
       temp = temp->link;
       count++;
   }

   if(temp == NULL)
   {
       free(new1);
       return POSITION_NOT_FOUND;
   }

   new1->link = temp->link;
   temp->link = new1;

   return SUCCESS;
}
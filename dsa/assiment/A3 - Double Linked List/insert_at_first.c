#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
  
   Dlist *new1 = malloc(sizeof(Dlist));
   
   if(new1 == NULL)
   {
     return FAILURE;
   }
    
    new1->data = data;
    new1->prev = NULL;
   
   if(*head == NULL)
   {
       new1->next = NULL;
       *head = new1;
       *tail = new1;
       
       return SUCCESS;
   }
   
   new1->next = *head;
   (*head)->prev = new1;
   *head = new1;
   
   return SUCCESS;
  
}
#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
   if(*head == NULL)
   {
       return FAILURE;
   }
   
   Dlist*temp = *head;
   Dlist*next;
   
   while(temp != NULL)
   {
      next = temp->next;
      free(temp);
      temp = next;
   }
   
   *head = NULL;
   *tail = NULL;
   
}
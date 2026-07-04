#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
 
  if(*head == NULL)
  {
    return FAILURE;
  }
  
  Dlist*temp = *tail;
  
  if(*head == *tail)
  {  

     *head = NULL;
     *tail = NULL;
     free(temp);
     
     return SUCCESS;
  } 
 
    
   (*tail)->prev->next = NULL;
   *tail = (*tail)->prev;
   free(temp);
   
   return SUCCESS;

}
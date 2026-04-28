#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
  if(*head == NULL)
  {
    return FAILURE;
  }
  
  Dlist*temp = *head;
  
  if(*head == *tail)
  {
       free(temp);
      *head = NULL;
      *tail = NULL;
      
      return SUCCESS;
  }
  
  *head = temp->next;
  (*head)->prev = NULL;
  free(temp);
  
  return SUCCESS;
  
}
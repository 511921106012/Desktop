#include "sll.h"

int sl_delete_list(Slist **head)
{
  if(*head == NULL)
  {
      return FAILURE;
  }	
  
  Slist*temp = *head;
  Slist*next;
  
  while(temp != NULL)
  {
      next = temp->link;
      free(temp);
      temp = next;
  }
  
  *head = NULL;
  
  return SUCCESS;
}
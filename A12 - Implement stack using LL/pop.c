#include "stack.h"

int Pop(Stack_t **top)
{
  
  if(*top == NULL)
  {
      return FAILURE;
  }	
 
 *top = (*top)->link;
 
 return SUCCESS;
 
}
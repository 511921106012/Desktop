#include "stack.h"

int Push(Stack_t **top, data_t data)
{
  Stack_t * new1 = malloc(sizeof(Stack_t)); 
  
   if(new1 == NULL)
   {
       return FAILURE;
   }
   
   new1->data = data;
   new1->link = *top;
   *top = new1;
   
    return SUCCESS;
   
}
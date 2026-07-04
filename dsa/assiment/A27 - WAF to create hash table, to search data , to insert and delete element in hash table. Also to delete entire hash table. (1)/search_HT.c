#include"hash.h"

int search_HT(hash_t *arr, int data, int size)
{
    
    int index = data % size;
    
    if(arr[index].value == data)
    {
        return SUCCESS;
    }
    
      hash_t * temp1 = arr[index].link;
      
      while(temp1 != NULL)
      {
          if(temp1->value == data)
          {
              return SUCCESS;
          }
          else
          {
              temp1 = temp1->link;
          }
      }
      
      return DATA_NOT_FOUND;
          
}
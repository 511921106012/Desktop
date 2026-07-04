#include"hash.h"

int delete_element(hash_t *arr, int data, int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i].value == data && arr[i].link == NULL)
        {
            arr[i]. value = -1;
            return SUCCESS;
        }
        
        if(arr[i].value == data && arr[i].link != NULL)
        {
            hash_t *temp = arr[i].link;
            
            arr[i].value = temp->value;
            arr[i].link = temp->link;
            free(temp);
            return SUCCESS;
            
        }
         
         hash_t *prev = arr[i].link;
         hash_t *temp = prev;
         
         while(temp != NULL)
        {
          if(temp->value == data)
          {
              prev->link = temp->link;
              free(temp);
              return SUCCESS;
          }
          prev = temp;
          temp = temp->link;
        }
    }
    
    
    return DATA_NOT_FOUND;;
}
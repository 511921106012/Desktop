#include "main.h"


int merge_sort(int *array, int narray)
{
        if(narray == 1)
        {
            return;
        } 
         
        
        int mid = narray/2;
        
        int *lsa = malloc(mid*sizeof(int));
    
        if(lsa == NULL)
        {
            return FAILURE;
        }
        
        for(int i=0;i<mid;i++)
        {
            lsa[i] = array[i];
        }
        
        int *rsa = malloc((narray-mid)*sizeof(int));
        
        if(rsa == NULL)
        {
          return FAILURE;
        }
        
        for(int i=mid;i<narray;i++)
        {
           rsa[i-mid] = array[i]; 
        }
        
        
        merge_sort(lsa,mid);
        merge_sort(rsa,narray-mid);
        merge(array,narray,lsa,mid,rsa,narray-mid);
        
        free(lsa);
        free(rsa);
        
}


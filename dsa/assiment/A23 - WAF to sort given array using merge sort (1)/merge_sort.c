#include "main.h"


int merge_sort(int *array, int narray)
{
    if(narray<=1)
    {
        return 0;
    }
   int mid=narray/2;
   int *lsa=malloc(sizeof(int)*mid);
   if(lsa == NULL)
   {
       printf("Memory lsa\n");
       return 0;
   }
   for(int i=0;i<mid;i++)
   {
       lsa[i]=array[i];
   }
   int *rsa=malloc(sizeof(int)*(narray-mid));
   if(rsa == NULL)
   {
       printf("Memory rsa\n");
       return 0;
   }
   for(int i=mid;i<narray;i++)
   {
       rsa[i-mid]=array[i];
   }
   merge_sort(lsa,mid);
   merge_sort(rsa,narray-mid);
   merge(array,narray,lsa,mid,rsa,narray-mid);
   free(lsa);
   free(rsa);
   return 1;
}

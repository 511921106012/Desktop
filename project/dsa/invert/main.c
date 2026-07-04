#include"john.h

hash *h_table = NULL ; /*allocate in main not at file scope */
file_list *head = NULL;
 int status = 0; int c=0; int u=0;

 int main(int argc ,char *argv[])
 {
 /* allocate  hash table : 26 letter + digits + other = 28 buckets*/
  h_table = calloc(28,sizeof(hash));
  if(h_table == NULL)
  {
  fprintf("stderr , Memory allocation failed for hash table \n");
  return FAILURE;
    }


    if(argc< 2)
    {
    

    }
 }

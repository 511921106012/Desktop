#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
    
    if(head== NULL)
    {
    return  LIST_EMPTY;    
    
    }
    
    Slist *temps=head;
    Slist *templ=head;
    while(temps->link != NULL)
    {
        if((temps == templ)&&(temps != head)&&(templ != head))
        {
            return SUCCESS;
        }
        temps=temps->link;
        if((templ != NULL)&&(templ->link != NULL))
        {
        templ=templ->link->link;
        }
    }
   return LOOP_NOT_FOUND;
}
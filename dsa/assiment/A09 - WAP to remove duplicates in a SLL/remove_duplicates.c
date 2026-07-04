#include "sll.h"

//remove duplicate data's from list
int remove_duplicates( Slist **head )
{
    if(*head==NULL)
    {
        return FAILURE;
    }
    Slist *temp1=*head;
    while(temp1!=NULL)
    {
        Slist *prev=temp1;
        Slist *temp2=temp1->link;
        while(temp2!=NULL)
        {
            if(temp1->data == temp2->data)
            {
                if(temp2->link==NULL)
                {
                    prev->link=NULL;
                    free(temp2);
                    break;
                }
                prev->link=temp2->link;
                free(temp2);
                temp2=prev;
            }
            prev=temp2;
            temp2=temp2->link;
        }
        temp1=temp1->link;
    }
}
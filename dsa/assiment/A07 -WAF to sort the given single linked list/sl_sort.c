#include "sll.h"

int sl_sort(Slist **head)
{
    if(*head==NULL)
    {
        return LIST_EMPTY;
    }
    Slist *temp=*head;
    Slist *prev1=NULL;
    Slist *prev2=NULL;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    temp=*head;
    if(count>1)
    {
        for(int i=0;i<count-1;i++)
        {
            temp=(*head)->link;
            prev2=*head;
            prev1=NULL;
            for(int j=0;j<count-1;j++)
            {
                if(prev2->data > temp->data)
                {
                    if(prev1==NULL)
                    {
                        prev2->link=temp->link;
                        temp->link=prev2;
                        *head=temp;
                        prev2=*head;
                        temp=prev2->link;
                    }
                    else
                    {
                        prev1->link=prev2->link;
                        if(temp->link==NULL)
                        {
                            prev2->link=NULL;
                        }
                        else
                        {
                            prev2->link=temp->link;
                        }
                        temp->link=prev2;
                        prev2=prev1->link;
                        temp=prev2->link;
                    }

                }
                prev1=prev2;
                prev2=temp;
                temp=temp->link;
            }
        }
    }
    return SUCCESS;
}
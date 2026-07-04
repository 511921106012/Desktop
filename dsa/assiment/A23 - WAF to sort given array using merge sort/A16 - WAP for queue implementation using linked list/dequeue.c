#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    Queue_t *temp=*front;
    if(*front==NULL)
    {
        return FAILURE;   
    }
    else if(*front==*rear)
    {
        *front=NULL;
        *rear=NULL;
        free(temp);
        return SUCCESS;
    }
    *front=temp->link;
    (*rear)->link=*front;
    free(temp);
    return SUCCESS;
}
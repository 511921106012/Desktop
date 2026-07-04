#include "queue.h"

int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    Queue_t *new=malloc(sizeof(Queue_t));
    new->data=data;
    if(new==NULL)
    {
        return FAILURE;
    }
    if(*front==NULL && *rear==NULL)
    {
        *front=new;
    }
    else
    {
        (*rear)->link=new;
    }
    *rear=new;
    new->link=*front;
    return SUCCESS;
}
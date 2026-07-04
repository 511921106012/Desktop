#include<stdio.h>
#include "apc.h"
#include <stdlib.h>

int digit_to_list(char *num, Dlist **head, Dlist **tail)
{
    if (num == NULL || *num == '\0') return FAILURE;

    for (int i = 0; num[i]; i++)
    {
        /* each char must be '0'..'9' (already validated earlier) */
        Dlist *new = malloc(sizeof(Dlist));
        if (new == NULL) return FAILURE;
        new->prev = NULL;
        new->data = num[i] - '0';
        new->next = NULL;

        if (*head == NULL)
        {
            *head = new; *tail = new;
        }
        else
        {
            new->prev = *tail;
            (*tail)->next = new;
            *tail = new;
        }
    }
    /* ensure no leading zeros in list representation */
    remove_leading_zeros_list(head, tail);
    return SUCCESS;
}

int insert_at_first(Dlist **head,Dlist **tail,int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        printf("Memory allocation is failed\n");
        return FAILURE;
    }
    new->prev=NULL;
    new->data=data;
    new->next=NULL;
    if((*head)==NULL && (*tail)==NULL)
    {
       *head=new;
       *tail=new;
       return SUCCESS;
    }
    else
    {
        new->next=*head;
        (*head)->prev=new;
        *head=new;
        return SUCCESS;
    }
}

int insert_at_last(Dlist **head,Dlist ** tail,int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        printf("Memory allocation is failed\n");
        return FAILURE;
    }
    new->prev=NULL;
    new->data=data;
    new->next=NULL;
    if((*head)==NULL && (*tail)==NULL)
    {
       *head=new;
       *tail=new;
       return SUCCESS;
    }
    else
    {
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;
        return SUCCESS;
    }
}

void print_the_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

int compare_the_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2)
{
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    int count1 =0,count2=0;
    while(temp1 != NULL)
    {
        temp1 = temp1->next;
        count1++;
    }
    while(temp2 != NULL)
    {
        temp2 = temp2->next;
        count2++;
    }
    if(count2 < count1)
    return 1;
    if(count1 < count2)
    return 2;
    temp1 = *head1;
    temp2 = *head2;
    while(temp1 != NULL)
    {
        if(temp1 -> data  < temp2 -> data)
        return 2;
        if(temp1 -> data > temp2 -> data)
        return 1;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return 0;
}

int delete(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        *tail = NULL;
        return SUCCESS;
    }
    else
    {
        Dlist *temp=*head;
        while(temp!=NULL)
        {
            *head=temp->next;
            free(temp);
            temp=*head;
        }
        *head=NULL;*tail=NULL;
        return SUCCESS;
    }
}

void remove_leading_zeros_list(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && (*head)->next != NULL)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    if (*head)
    {
        Dlist *t = *head;
        while (t->next)
            t = t->next;
        *tail = t;
    }
}

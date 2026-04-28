#include "INDEX.h"

int insert_at_last(file_list **head, char *data)
{
    file_list *new=malloc(sizeof(file_list));
    if(new==NULL)
    {
        return FAILURE;
    }
    strcpy(new->file_name,data);
    new->link=NULL;
    if(*head == NULL)
    {
        *head=new;
        return SUCCESS;
    }
    else
    {
        file_list *temp = *head;
        while(temp->link !=NULL)
        {
            temp=temp->link;//traversal
        }
        temp->link=new;
        return SUCCESS;
    }
}

int find_node(file_list *head, char * data)
{
	if(head == NULL)
    {
        return FAILURE;
    }
    else
    {
        int count=1;
        file_list *temp=head;
        while(temp != NULL)
        {
            if(strcmp(temp->file_name,data)==0)
            {
                return SUCCESS;
            }
            else
            {
                count++;
                temp=temp->link;
            }
        }
        return FAILURE;
        
    }
}


/* Insert a new Main_list node at the front of hash bucket HT[index].next_main
   */
int insert_at_first_main(Hash *HT, int index, char *word, int file_count)
{
    if (HT == NULL || index < 0)
        return FAILURE;

    Main_list *new = (Main_list *)malloc(sizeof(Main_list));
    if (new == NULL)
        return FAILURE;

    new->file_count = file_count;
    strcpy(new->word, word);
    new->sub_link = NULL;

    /* insert at beginning of the main list */
    new->main_link = HT[index].next_main;
    HT[index].next_main = new;

    //HT[index].index = index;

    return SUCCESS;
}

/* Insert a new Sub_list node at the front of the given main node's sub list
   */
int insert_at_first_sub(Main_list *m, char *filename, int wc)
{
    if (m == NULL)
        return FAILURE;

    Sub_list *new = (Sub_list *)malloc(sizeof(Sub_list));
    if (new == NULL)
        return FAILURE;

    new->word_count = wc;
    strncpy(new->filename, filename, sizeof(new->filename) - 1);
    new->filename[sizeof(new->filename) - 1] = '\0';

    /* insert at beginning of sub list */
    new->next_sub = m->sub_link;
    m->sub_link = new;

    return SUCCESS;
}

void update_file_list(Hash *ht,file_list **head)
{
    for(int i=0;i<28;i++)
    {
        Main_list* m=ht[i].next_main;
        while(m)
        {
            Sub_list *s=m->sub_link;
            while(s)
            {
                remove_file(s->filename,head);
                s=s->next_sub;
            }
            m=m->main_link;
        }
    }
}


void remove_file(char *data,file_list **head)
{
    file_list * temp=*head;
    file_list *prev=NULL;
    while(temp!=NULL)
    {
        if(strcmp(temp->file_name,data)==0)
        {
            if(*head == temp)
            {
                (*head)=temp->link;
                free(temp);
            }
            else
            {
                prev->link=temp->link;
                free(temp);
            }
            return SUCCESS;
        }
        prev=temp;
        temp=temp->link;
    }
}


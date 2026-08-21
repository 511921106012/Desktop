#include "header.h"

int n_sign1 =1;
int n_sign2 =1;

void error_message()
{
   printf("Opreator Should be + or - or x or /\n");
   printf("Operands should contain only digits\n");
   printf("Syntax is a.out    operand1    opreator    operand2\n"RESET); 
}

int validate_inputs(char *argv[],int argc)
{
    if(argc < 4)
    {
        printf(RED"ERROR : Insufficient Arguments\n");
        return FAILURE;
    }
    int i=0;
    if(argv[1][i] == '-')
    {
        i=1;
        n_sign1=-1;
    }
    else if(argv[1][i] == '+')
    {
        i=1;
    }
    for(i;argv[1][i];i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf(RED"ERROR : Operand1 Error\n");
            return FAILURE;
        }
    }
    if(strcmp(argv[2],"+") && strcmp(argv[2],"-") && strcmp(argv[2],"x") && strcmp(argv[2],"/"))
    {
        printf(RED"ERROR : Invalid operator\n");
        return FAILURE;
    }
    i=0;
    if(argv[3][i] == '-')
    {
        i=1;
        n_sign2=-1;
    }
    else if(argv[3][i] == '+')
    {
        i=1;
    }
    for(i;argv[3][i];i++)
    {
        if(!isdigit(argv[3][i]))
        {
            printf(RED"ERROR : Operand2 Error\n");
            return FAILURE;
        }
    } 
    return SUCCESS;
}

void digit_to_list(node **head, node **tail,char *argv[],int index)
{
    int i=0;
    if(argv[index][i] == '-')
    {
        i=1;
    }
    if(argv[index][i] == '+')
    {
        i=1;
    }
    for(i;argv[index][i];i++)
    {
        insert_last(head,tail,argv[index][i]-'0');
    }
}

int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if(new == NULL)
    {
        printf("memory allocation failed\n");
        return FAILURE;
    }
    if(*head == NULL)
    {
        new -> data = data;
        new -> prev = NULL;
        new -> next = NULL;
        *head = new;
        *tail = new;
        return SUCCESS;  
    }
    new ->data = data;
    new -> next = NULL;
    new -> prev = *tail;
    (*tail)->next = new;
    *tail = new;
    return SUCCESS;
}

void print_list(node *head)
{
	if (head == NULL)
	{
		printf("0");
	}
	else
	{
	    while (head)		
	    {
		    printf("%d", head -> data);
		    head = head -> next;
	    }
    }
}

void addition(node **head1, node **tail1,node **head2,node **tail2,node **headR,node **tailR)
{
    int carry = 0, res = 0;
    int data1 = 0, data2 = 0;
    node *temp1 = *tail1;
    node *temp2 = *tail2;
    if(temp1 != NULL)
    data1 = temp1 ->data;
    if(temp2 != NULL)
    data2 = temp2 ->data;
    while(temp1 != NULL || temp2 != NULL )
    {
        res = data1 + data2 + carry;
        carry = res/10;
        res = res % 10;
        insert_first(headR,tailR,res);
        if(temp1 != NULL)
            temp1 = temp1 -> prev;    
        if(temp1 != NULL)
            data1 = temp1->data;    
        else
            data1 = 0;
        if(temp2 != NULL)
            temp2 = temp2 ->prev;  
        if(temp2 != NULL)
            data2 = temp2->data;    
        else
            data2 = 0;
    }
    if(carry == 1)
    {
        insert_first(headR,tailR,carry);
    }
}

int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if(new == NULL)
    {
        printf("memory allocation failed\n");
        return FAILURE;
    }
    if(*head == NULL)
    {
        new -> data = data;
        new -> prev = NULL;
        new -> next = NULL;
        *head = new;
        *tail = new;
        return SUCCESS;  
    }
    new ->data = data;
    new -> prev = NULL;
    new -> next = *head;
    (*head)->prev = new;
    *head = new;
    return SUCCESS;
}

int delete_list(node **head, node **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    node *temp = *head;
    while(temp != NULL)
    {
        *head = temp ->next;
        free(temp);
        temp = *head;
        if(temp!=NULL)
        temp -> prev = NULL;
    }
    *tail = NULL;
}

int is_grater(node **head1,node **tail1,node **head2,node **tail2)
{
    node *temp1 = *head1;
    node *temp2 = *head2;
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
    return 1;
}

void subtraction(node **head1,node **tail1,node **head2,node **tail2,node **headR,node **tailR)
{
    int rec = is_grater(head1,tail1,head2,tail2);
    int borrow=0,res =0;;
    node *temp1 = *tail1;
    node *temp2 = *tail2;
    if(rec == 2)
    {
        temp1 = *tail2;
        temp2 = *tail1;
    }
    int data1 = 0,data2=0;
    if(temp1 != NULL)
    data1 = temp1 -> data;
    if(temp2 != NULL)
    data2 = temp2 -> data;
    while(temp1 != NULL || temp2 != NULL)
    {
        if(borrow == 1)
        {
            data1 = data1 -1;
            borrow =0;
        }
        if(data1 < data2)
        {
            data1 = data1 +10;
            borrow = 1;
        }
        res = data1 - data2;
        insert_first(headR,tailR,res);

        if(temp1 != NULL)
            temp1 = temp1 -> prev;    
        if(temp1 != NULL)
            data1 = temp1->data;    
        else
            data1 = 0;
        if(temp2 != NULL)
            temp2 = temp2 ->prev;  
        if(temp2 != NULL)
            data2 = temp2->data;    
        else
            data2 = 0;
    }
}

void multiplication(node **head1,node **tail1,node **head2,node **tail2,node **headR,node **tailR)
{
    int carry =0,num_zeros = 0,res=0;
    node *temp1 = *tail1,*temp2 = *tail2;
    node *headR1, *tailR1, *headR2,*tailR2;
    headR1 = tailR1 = headR2 = tailR2 = NULL;
    while(temp2 != NULL)
    {
        temp1 = *tail1;
        carry =0;
        for(int i=0;i<num_zeros; i++)
        {
            insert_first(&headR1,&tailR1,0);
        }
        while(temp1 != NULL)
        {
            res = temp1 ->data * temp2 ->data + carry;
            carry = res/10;
            res = res % 10;
            insert_first(&headR1,&tailR1,res);
            temp1 = temp1 ->prev;  
        }
        if(carry)
        insert_first(&headR1,&tailR1,carry);
        if(*headR == NULL)
        {
            *headR = headR1;
            *tailR = tailR1;
            headR1 = tailR1= NULL;
        }
        if(headR != NULL && headR1 != NULL)
            {  
                addition(headR,tailR,&headR1,&tailR1,&headR2,&tailR2);
                delete_list(headR,tailR);
                delete_list(&headR1,&tailR1);
                *headR = headR2;
                *tailR = tailR2;
                headR2 = tailR2 = NULL;
            }    
        temp2 = temp2 -> prev;
        num_zeros++;
    }
}

int get_element(node **ptr)
{
    if(*ptr == NULL)
    return FAILURE;
    int data = (*ptr)->data;
    return data;
}

void remove_trailing_zeros(node **head,node **tail)
{ 
    node *temp = *head;
    while(temp != NULL && temp -> data == 0)
    {   
        temp = temp->next;       
        delete_first(head,tail);
    }
}

int delete_first(node **head,node **tail)
{   
    if(*head == NULL)
    {
        return FAILURE;
    }
    if(*head == *tail)
    {
        free(*tail);
        *head = *tail = NULL;
        return SUCCESS;
    }
    (*head) = (*head)->next;
    free((*head)->prev);
    (*head)->prev = NULL;
    return SUCCESS;
}

void division(node **head1,node **tail1,node **head2,node **tail2,node **headR,node **tailR)
{
    int count =0,res=0;
    node *temp = *head1;
    node *t_head, *t_tail, *rem_head, *rem_tail;
    t_head = t_tail = rem_head = rem_tail = NULL;
    if(*head2 == NULL)
    {
        printf(YELLOW"We can not divide number with ZERO\n");
        return;
    }
    while(temp != NULL)
    {
        res = get_element(&temp);
        insert_last(&t_head,&t_tail,res);
        int big = is_grater(&t_head,&t_tail,head2,tail2);
        remove_trailing_zeros(&t_head,&t_tail);
        while(big == 1)
        {
            subtraction(&t_head,&t_tail,head2,tail2,&rem_head,&rem_tail);
            count++;
            delete_list(&t_head,&t_tail);
            t_head = rem_head;
            t_tail = rem_tail;
            rem_head = rem_tail = NULL;
            remove_trailing_zeros(&t_head,&t_tail);
            big = is_grater(&t_head,&t_tail,head2,tail2);
        }
        insert_last(headR,tailR,count);
        count = 0;
        temp = temp -> next;
    }
}
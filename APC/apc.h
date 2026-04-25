#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
    struct node *prev;
    data_t data;
    struct node *next;
}Dlist;

/* Keep original prototypes / names */
int digit_to_list(char *num,Dlist **head,Dlist **tail);
int validate_operand(char *argv[]);
int my_isdigit(char* arr);
int valid_operator(char *str);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int insert_at_first(Dlist **head,Dlist **tail,int data);
void  print_the_list(Dlist *head);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int compare_the_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int delete(Dlist **head, Dlist **tail);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int insert_at_last(Dlist **temph,Dlist ** tempt,int data);
void remove_leading_zeros_list(Dlist **head, Dlist **tail);

#endif

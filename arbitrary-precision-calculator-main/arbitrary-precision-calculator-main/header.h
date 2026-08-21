#ifndef header_h
#define header_h

#define SUCCESS 0
#define FAILURE -1


#define RED         "\033[1;3;31m"
#define GREEN       "\033[1;3;32m"
#define YELLOW      "\033[1;3;33m"
#define BLUE        "\033[1;3;34m"
#define MAGENTA     "\033[1;3;35m"
#define CYAN        "\033[1;3;36m"
#define RESET       "\033[0m"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;


void error_message();

int validate_inputs(char *argv[],int argc);

void digit_to_list(node **head, node **tail,char *argv[],int index);

int insert_last(node **head, node **tail, int data);

int insert_first(node **head, node **tail, int data);

int delete_list(node **head, node **tail);

int delete_first(node **head,node **tail);

void remove_trailing_zeros(node **head,node **tail);

void print_list(node *head);

void addition(node **head1, node **tail1,node **head2,node **tail2,node **headR,node **tailR);

int is_grater(node **head1,node **tail1,node **head2,node **tail2);

void subtraction(node **head1,node **tail1,node **head2,node **tail2,node **headR,node **tailR);

void multiplication(node **head1,node **tail1,node **head2,node **tail2,node **headR,node **tailR);

void division(node **head1,node **tail1,node **head2,node **tail2,node **headR,node **tailR);
#endif
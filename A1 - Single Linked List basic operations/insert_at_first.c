#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{
	Slist *new1 = malloc(sizeof(Slist));
	
	if(new1 == NULL)
	return FAILURE;
	
	new1->data = data;
	new1->link = NULL;
	
	new1->link = *head;
	*head = new1;
	   
	return SUCCESS;
	
}
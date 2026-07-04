#include<stdio.h>
#include "apc.h"
#include <stdlib.h>

/* validate_operand kept original signature: expects argv array */
int validate_operand(char *argv[])
{
    if (my_isdigit(argv[1]) == FAILURE)
        return FAILURE;

    if (my_isdigit(argv[3]) == FAILURE)
        return FAILURE;

    return SUCCESS;
}

/* my_isdigit: allows optional leading + or - and at least one digit */
int my_isdigit(char* str)
{
    if (str == NULL || *str == '\0') return FAILURE;

    int i = 0;
    if (str[0] == '+' || str[0] == '-') i = 1;

    /* must have at least one digit after optional sign */
    if (str[i] == '\0') return FAILURE;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return FAILURE;
    }
    return SUCCESS;
}

/* only accept + - x X / as operator (single char arg) */
int valid_operator(char *str)
{
    if (str[1] != '\0') return FAILURE;
    if (str[0] != '+' && str[0] != '-' && str[0] != 'x' && str[0] != 'X' && str[0] != '/' )
        return FAILURE;
    return SUCCESS;
}

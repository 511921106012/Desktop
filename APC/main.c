


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"

void normalize_str(const char *in, char *out, int *sign);

int main(int argc,char * argv[])
{
    if(argc<4)
    {
        printf("INVALID INPUT\n");
        printf("<operand 1> <operator> <operand 2>\n");
        printf("ENTER VALID OPERATOR + , - , x ,/ \n");
        return FAILURE;
    }

    if(valid_operator(argv[2])!=SUCCESS)
    {
        printf("\n");
        printf("INVALID OPERATOR!!! ENTER VALID OPERATOR + , - , x ,/ \n");
        printf("<operand 1> <operator> <operand 2>\n");
        return FAILURE;
    }
    if (validate_operand(argv)==FAILURE)
    {
        printf("\n");
        printf("INVALID INPUT!!! ENTER ONLY DIGITS!!!\n");
        printf("<operand 1> <operator> <operand 2>\n");
        return FAILURE;
    }

    /* normalize and extract signs */
    char s1[2048], s2[2048];
    int sign1 = 1, sign2 = 1;
    normalize_str(argv[1], s1, &sign1);
    normalize_str(argv[3], s2, &sign2);

    /* division by zero check (message requested earlier) */
    if (argv[2][0] == '/' && strcmp(s2, "0") == 0)
    {
        printf("INVALID: Cannot divide a number by 0!\n");
        return FAILURE;
    }

    Dlist *head1=NULL; Dlist *tail1=NULL;
    Dlist *head2=NULL; Dlist *tail2=NULL;
    Dlist *headR=NULL; Dlist *tailR=NULL;
    char operator;

    if (digit_to_list(s1, &head1, &tail1) == FAILURE) { printf("Memory error\n"); return FAILURE; }
    if (digit_to_list(s2, &head2, &tail2) == FAILURE) { delete(&head1,&tail1); printf("Memory error\n"); return FAILURE; }

    operator = argv[2][0];

    int res;

    switch(operator)
    {
        case '+':
            if (sign1 == sign2)
            {
                res = addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                if (res != SUCCESS) { printf("Error\n"); return FAILURE; }
                printf("addition of %s and %s is : ",argv[1],argv[3]);
                if (!(headR->data == 0 && headR->next == NULL) && sign1 < 0)
                    printf("-");
                
                print_the_list(headR);
            }
            else
            {
                int cmp = compare_the_list(&head1,&tail1,&head2,&tail2);

                if (cmp == 0)
                {
                    printf("addition of %s and %s is : ",argv[1],argv[3]);
                    printf("0\n");
                }
                else if (cmp == 1)
                {
                    res = subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    if (res != SUCCESS) { printf("Error\n"); return FAILURE; }

                     printf("addition of %s and %s is : ",argv[1],argv[3]);
                    if (!(headR->data == 0 && headR->next == NULL) && sign1 < 0)
                        printf("-");
                       

                    print_the_list(headR);
                }
                else
                {
                    res = subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                    if (res != SUCCESS) { printf("Error\n"); return FAILURE; }

                    printf("addition of %s and %s is : ",argv[1],argv[3]);
                    if (!(headR->data == 0 && headR->next == NULL) && sign2 < 0)
                        printf("-");

                    print_the_list(headR);
                }
            }
            break;

        case '-':
            if (sign1 != sign2)
            {
                res = addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                if (res != SUCCESS) { printf("Error\n"); return FAILURE; }


                printf("Subtraction of %s and %s is : ",argv[1],argv[3]);

                if (!(headR->data == 0 && headR->next == NULL) && sign1 < 0)
                    printf("-");

                print_the_list(headR);
            }
            else
            {
                int cmp = compare_the_list(&head1,&tail1,&head2,&tail2);

                if (cmp == 0)
                {
                    printf("Subtraction of %s and %s is : ",argv[1],argv[3]);
                    printf("0\n");
                }
                else if (cmp == 1)
                {
                    res = subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    if (res != SUCCESS) { printf("Error\n"); return FAILURE; }

                    printf("subtraction of %s and %s is : ",argv[1],argv[3]);
                    if (!(headR->data == 0 && headR->next == NULL) && sign1 < 0)
                        printf("-");

                    print_the_list(headR);
                }
                else
                {
                    res = subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                    if (res != SUCCESS) { printf("Error\n"); return FAILURE; }

                    printf("subtraction of %s and %s is : ",argv[1],argv[3]);
                    if (!(headR->data == 0 && headR->next == NULL))
                        //printf("-");

                    print_the_list(headR);
                }
            }
            break;

        case 'x':
        case 'X':
            res = multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            if (res != SUCCESS) { printf("Error\n"); return FAILURE; }

            printf("multiplication of %s and %s is : ",argv[1],argv[3]);
            if (!(headR->data == 0 && headR->next == NULL) && (sign1 * sign2 < 0))
                printf("-");

            print_the_list(headR);
            break;

        case '/':
        {
            int cmp = compare_the_list(&head1,&tail1,&head2,&tail2);

            if (cmp == 2)
            {
                printf("Division of %s and %s is : ",argv[1],argv[3]);
                printf("0\n");
            }
            else
            {
                res = division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                if (res != SUCCESS) { printf("Error\n"); return FAILURE; }

                printf("Division of %s and %s is : ",argv[1],argv[3]);
                if (!(headR->data == 0 && headR->next == NULL) && (sign1 * sign2 < 0))
                    printf("-");

                print_the_list(headR);
            }
            break;
        }

        default:
            printf("Invalid Input :-( Try again...\n");
    }


    delete(&head1,&tail1);
    delete(&head2,&tail2);
    delete(&headR,&tailR);

    return 0;
}

/* helper: remove leading zeros from a digit string, returns pointer to start in buf */
void normalize_str(const char *in, char *out, int *sign)
{
    int i = 0, j = 0;
    *sign = 1;
    if (!in) 
    {
        out[0]='\0'; 
        return; 
    }

    if (in[0] == '+' || in[0] == '-')
    {
        if (in[0] == '-') *sign = -1;
        i = 1;
    }

    /* skip leading zeros */
    while (in[i] == '0') i++;

    if (in[i] == '\0') /* number is 0 (or -0) */
    {
        out[0] = '0';
        out[1] = '\0';
        *sign = 1; /* normalize -0 to 0 */
        return;
    }

    while (in[i])
    {
        out[j++] = in[i++];
    }
    out[j] = '\0';
}


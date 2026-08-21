#include "header.h"

extern int n_sign1 ;
extern int n_sign2 ;
int sign = 1;

int main(int argc,char *argv[])
{
    if(validate_inputs(argv,argc)==FAILURE)
    {
        error_message();
        return FAILURE;
    }
    printf(MAGENTA"INFO : Input Arguments Verified Successfully\n"RESET);

    node *head1, *tail1, *head2, *tail2, *headR, *tailR;
    head1 = tail1 = head2 = tail2 = headR = tailR = NULL;
    digit_to_list(&head1,&tail1,argv,1);
    digit_to_list(&head2,&tail2,argv,3);
    remove_trailing_zeros(&head1,&tail1);
    remove_trailing_zeros(&head2,&tail2);
    switch (argv[2][0])
    {
        case '+':
        {
            if(n_sign1 == -1 && n_sign2 == -1)
            {
                sign = -1;
            }
            if(n_sign1*n_sign2 == 1)
            addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            if(n_sign1*n_sign2 == -1)
            {
                int ret = is_grater(&head1,&tail1,&head2,&tail2);
                subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                remove_trailing_zeros(&headR,&tailR);
                if(ret == 1)
                sign = 1 * n_sign1;
                else
                sign = 1 * n_sign2;
            }
            printf(YELLOW "Addition of %s and %s is ",argv[1],argv[3]);
            if(sign == -1 && headR != NULL)
            printf("-");
            print_list(headR);
            printf("\n"RESET);
            break;
        }
        case '-':
        {
            printf(YELLOW "Subtraction of %s from %s is ",argv[1],argv[3]);
            int ret = is_grater(&head1,&tail1,&head2,&tail2);
            if(n_sign1*n_sign2 == 1)
            subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            if(n_sign1*n_sign2 == -1)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            }
            if(n_sign1 == 1 && n_sign2 == 1 && ret == 2)
            {
                sign = -1;
            }
            else if(n_sign1 == 1 && n_sign2 == 1 && ret == 1)
            {
                sign = 1;
            }
            else if(n_sign1 * n_sign2 ==1 && ret == 1)
            {
                sign = -1;
            }
            else if(n_sign1 == 1 && n_sign2 == -1 )
            {
                sign = 1;
            }
            else if(n_sign1 == -1 && n_sign2 == 1)
            {
                sign = -1;
            }
            if(sign == -1 &&  headR != NULL)
            printf("-");
            remove_trailing_zeros(&headR,&tailR);
            print_list(headR);
            printf("\n"RESET);
            break;
        }
        case 'x':
        {
            multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            printf(YELLOW "Multiplication of %s and %s is ",argv[1],argv[3]);
            if(n_sign1*n_sign2 == -1 && headR != NULL)
            printf("-");
            print_list(headR);
            printf("\n"RESET);
            break;
        }
        case '/':
        {
            division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            printf(YELLOW "Division of %s and %s is ",argv[1],argv[3]);
            if(n_sign1*n_sign2 == -1 && headR != NULL)
            printf("-");
            remove_trailing_zeros(&headR,&tailR);
            print_list(headR);
            printf("\n"RESET);
            break;
        }
    }
}
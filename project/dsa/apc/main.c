#include<stdio.h>
int main(int argc, char *argv)
{

    // 2 validation of the argument add,sum,div,mlu it is oky it work it not it wont work 
    if(argc != 4)
    {
        printf("invalid input : ");
        printf("<operand 1> <operator> <operand 2>\n");
        printf("ENTER THE VALID OPERATOR + , - , x , / \n");
        return FAILURE;

    }
// argv & argv [3] is having 0 - a or not 

if(valid_operator(argv[2]!=SUCCESS))
{
    printf("\n");
    printf("INVALID OPERATOR !! ENTER VALID OPERATOR +,-,x,/ \n");
     printf("ENTER THE VALID OPERATOR + , - , x , / \n");
    return FAILURE; 
}
if(valid_operand(argv)==FAILURE)
{
    printf("\n")
}


    




    
}
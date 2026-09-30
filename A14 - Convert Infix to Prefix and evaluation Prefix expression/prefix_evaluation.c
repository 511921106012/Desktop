#include "main.h"

int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
    int i=0;
    
    while(Prefix_exp[i]!='\0')
    {
        
       char ch = Prefix_exp[i];
       
       if(isdigit(ch))
       {
          int digit = ch -'0';
          push(stk,digit);
       }
       else
       {
           int operand_1 = peek(stk);
           pop(stk);
           
           int operand_2 = peek(stk);
           pop(stk);
           
           int result = 0;
           
           switch(ch)
           {
               case '+':
               
               result = operand_1+operand_2;
               push(stk,result);
               
               break;
               
               case '-':
               
               result = operand_1-operand_2;
               push(stk,result);
               
               break;
               
               case '*':
               
               result = operand_1*operand_2;
               push(stk,result);
               
               break;
               
               case '/':
               
               result = operand_1/operand_2;
               push(stk,result);
               
               break;
           }
       }    
        
        i++;
    }
    
    return peek(stk);
}
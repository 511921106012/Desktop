
#include "main.h"

int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
    int i=0;
    
    while(Postfix_exp[i] != '\0')
    {
        char ch = Postfix_exp[i];
        
        if(isdigit(ch))
        {
            int digit = ch - '0';
            push(stk,digit);
        }
        else
        {
            int operand_2 = peek(stk); 
            pop(stk);
            int operand_1 = peek(stk); 
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
              
              default:
              
              return 1;
          }    
        }
        i++;
    }
    
    return peek(stk);
}
#include "main.h"

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
	int i=0,j=0;
	
	while(Infix_exp[i] != '\0')
	{ 
	    char ch = Infix_exp[i];
	    
	    if(isalnum(ch))
	    {
	       Postfix_exp[j++] = ch;
	    }
	    else if(ch == '(')
	    {
	        push(stk,ch);
	    }
	    else if(ch == ')')
	    {
	        while(stk->top != -1 && peek(stk) != '(')
	        {
	           Postfix_exp[j++] = peek(stk); 
	           pop(stk);
	        }
	        pop(stk);
	    }
	    else
	    {
	        while(stk->top != -1 && priority(ch) <= priority(peek(stk)))
	        {
	           Postfix_exp[j++] = peek(stk); 
	           pop(stk);
	        }
	        push(stk,ch);
	    }
	    
	    i++;
	}
	
	while(stk->top != -1)
	{
	    Postfix_exp[j++] = peek(stk); 
	    pop(stk);    
	}
	
	Postfix_exp[j] = '\0';
	
}
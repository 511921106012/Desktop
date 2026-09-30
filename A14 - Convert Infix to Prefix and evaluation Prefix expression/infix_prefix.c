#include "main.h"

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
	int i=0,j=0;
	
	while(Infix_exp[i]!= '\0')
	{
	    char ch = Infix_exp[i];
	    
	    if(isalnum(ch))
	    {
	      Prefix_exp[j++] = ch;  
	    }
	    else if(ch == ')')
	    {
	        push(stk,ch);
	    }
	    else if(ch == '(')
	    {
	        while(stk->top != -1 && peek(stk)!= ')' )
	        {
	           Prefix_exp[j++] = peek(stk);
	           pop(stk);
	        }
	        pop(stk);
	    }
	    else
	    {
	      while(stk->top != -1 && priority(ch) < priority(peek(stk)))
	      {
	         Prefix_exp[j++] = peek(stk);
	         pop(stk);
	      } 
	      
	      push(stk,ch);
	    }
	    
	    i++;
	}
	
	while(stk->top != -1)
	{
	   Prefix_exp[j++] = peek(stk);
	   pop(stk); 
	}
    
    Prefix_exp[j] = '\0';
}
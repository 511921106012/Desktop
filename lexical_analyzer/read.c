#include "header.h"

int flag=0;
int real_flag=0,real_flag1=0,pre_flag=0;
int curve_flag=0,square_flag=0,flower_flag=0,line=1;
char ch;
int read_fun(char *filename)
{
    FILE *fptr=fopen(filename,"r");
    if(fptr==NULL)
    {
        printf("Open failed\n");
        return 1;
    }
    // char ch;
    // int flag=0;
    // int real_flag=0,real_flag1=0,pre_flag=0;
    // int curve_flag=0,square_flag=0,flower_flag=0,line=1;
    while((ch=fgetc(fptr))!=EOF)
    {
        if(ch=='/')
        {
            int next=fgetc(fptr);
            if(next=='/')
            {
                while((ch=fgetc(fptr))!='\n' && ch!=EOF);
                line++;
                continue;
            }
            else if(next=='*')
            {
                int prev=0;
                while((ch=fgetc(fptr))!=EOF)
                {
                    if(prev=='*' && ch=='/')
                    break;
                    if(ch=='\n')
                    line++;
                    prev=ch;
                }
                continue;
            }
            else
            {
                ungetc(next,fptr);
            }
        }
        if(ch=='#' && pre_flag==0)
        {
            printf("%-22s : %c","PreProcessor Line",ch);
            while((ch=fgetc(fptr))!= '\n' && ch!=EOF)
            printf("%c",ch);
            printf("\n");
            // printf("PreProcessor Line\n");
        }
        char str[50];
        if(isalpha(ch))
        {
            pre_flag++;
            for(int i=0;i<50;i++,ch=fgetc(fptr))
            {
                if(isalnum(ch))
                {
                    str[i]=ch;
                }
                else
                {
                    str[i]='\0';
                    break;
                }  
            }
            str[49]='\0';
            identifier_keyword(str);
        }
        flag=0;
        real_flag=2;
        if(isdigit(ch))
        {
            pre_flag++;
            for(int i=0;i<50;i++,ch=fgetc(fptr))
            {
                if (ch == '.')
                {
                    str[i]=ch;
                    i++;
                    while(i<49 && (ch=fgetc(fptr))!=EOF)
                    {
                        if(isdigit(ch))
                        {
                            str[i]=ch;
                        }
                        else if (ch == ' ' || ch == ';' || ch=='\n')
                        {
                            str[i]='\0';
                            real_flag=0;
                            break;
                        }
                        else 
                        {
                            str[i]=ch;
                            real_flag1=1;
                        }
                        i++;
                    }
                    str[49]='\0';
                    if(real_flag==0)
                    break;
                }
                else if(isdigit(ch) || ch == 'x' || ch =='X' || ch >= 'A' && ch <= 'F' || ch >= 'a' && ch <= 'f')
                {
                    str[i]=ch;
                }
                else if(ch==' ' || ch ==';' || ch=='\n')
                {
                    str[i]='\0';
                    break;
                } 
                else if((ch >= 'G' && ch <='Z') || (ch >= 'g' && ch <= 'z'))
                {
                   str[i]=ch;
                   flag=1;
                }
                else
                {
                    str[i]='\0';
                    break;
                }   
            }
            str[49]='\0';
            if(real_flag1==1)
            {
                printf("%-22s : %s\n","Integer Value",str);
                printf("ERROR: Invalid Real Number\n");
                return 1;
            } 
            if(flag==1)
            {
                printf("%-22s : %s\n","Numerical",str);
                printf("ERROR: Invalid  Number\n");
                return 1;
            }
            if(real_flag==0)
            {
                printf("%-22s : %s\n","Real Number",str);
                str[0]='\0';
            }
            
            else if(str[0]=='0' && (str[1] =='x' || str[1]=='X') && strlen(str) > 2)
            {
                if(hexadecimal(str))
                {
                    printf("%-22s : %s\n","Hexadecimal Number",str);
                    printf("ERROR: Hexadecimal Value Error\n");
                    return 1;
                }
                printf("%-22s : %s\n","Hexadecimal Number",str);
            }
            else if(str[0]=='0' && (str[1] =='b' || str[1]=='B') && strlen(str) > 2)
            {
                if(binary(str))
                {
                    printf("%-22s : %s\n","Binary Number",str);
                    printf("ERROR: Binary Value Error\n");
                    return 1;
                }
                printf("%-22s : %s\n","Binary Number",str);
            }
            else if(str[0] == '0' && strlen(str) > 2)
            {
                if(octal(str))
                {
                    printf("%-22s : %s\n","Octal Number",str);
                    printf("ERROR: Octal Value Error\n");
                    return 1;
                }
                printf("%-22s : %s\n","Octal Number",str);
            }
            else
            {
                printf("%-22s : %s\n","Integer Value",str);
                str[0]='\0';
            }
        }
        if(ch=='"')
        {
            litral(str,ch,fptr);
        }
        
        if(ch=='(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' ||ch == '[' ||ch == ']')
        {
            printf("%-22s : %c\n","Special Character",ch);
            pre_flag++;
        }

        if(ch=='(' || ch == ')')
        {
            if(ch == '(')
            {
                curve_flag++;
            }
            else
            curve_flag--;
        }
        
        if(ch=='[' || ch == ']')
        {
            if(ch == '[')
            {
                square_flag++;
            }
            else
            square_flag--;
        }
        if(ch=='{' || ch == '}')
        {
            if(ch == '{')
            {
                flower_flag++;
            }
            else
            flower_flag--;
        }
        if(ch == '\n')
        { 
            if(curve_flag || square_flag)
            {
                printf("ERROR: Error in line number %d\n",line);
                pre_flag++;
                return 1;
            }
            pre_flag=0;
            line++;
        }
       
        if(ch== '+'|| ch == '-' || ch== '*' || ch == '/' || ch == '='|| ch == '<'||ch == '>'|| ch == '%'|| ch == '&'|| ch == '|'|| ch == ',')
        {
            printf("%-22s : %c\n","Operator",ch);
            pre_flag++;
        }    
    }
    if(flower_flag)
    {
        printf("ERROR: Flower Bracket Closing Error\n");
    }
    return 0;
}
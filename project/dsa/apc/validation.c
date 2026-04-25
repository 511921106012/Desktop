int valid_operator(char *str)
{
    if(str[1]!='\0')
    {return FAILURE;
    }
    if(str[0] !='+'&& str[0]!='-' && str[0] !='x'&& str[0] !='X'&& str[0] != '/')
     return FAILURE;
     return SUCCESS;
}
    
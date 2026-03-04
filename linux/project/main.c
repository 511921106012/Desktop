#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char prompt_str[20] = "mini_shell$ ";
    char str[100];

    system("clear");

    while(1)
    {
        printf("%s", prompt_str);
        fflush(stdout);

        scanf("%[^\n]", str);
        getchar();   // consume newline

        // Exit condition
        if(strcmp(str, "exit") == 0)
        {
            break;
        }

        // Check if input starts with PS1
        if(strncmp(str, "PS1=", 4) == 0)
        {
            char *equal_ptr = strchr(str, '=');

            // Validation 1: '=' must exist
            if(equal_ptr == NULL)
            {
                printf("Invalid input: '=' missing\n");
                continue;
            }

            equal_ptr++;   // move after '='

            // Skip spaces after '='
            while(*equal_ptr == ' ')
                equal_ptr++;

            // Validation 2: Prompt must not be empty
            if(*equal_ptr == '\0')
            {
                printf("Invalid input: Prompt empty\n");
                continue;
            }

            // Validation 3: Length check
            if(strlen(equal_ptr) >= sizeof(prompt_str))
            {
                printf("Invalid input: Prompt too long\n");
                continue;
            }

            strcpy(prompt_str, equal_ptr);
        }
        else
        {
            printf("Invalid input\n");
        }
    }

    return 0;
}
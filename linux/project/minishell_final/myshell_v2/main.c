#include "head.h"

/* ================================================
   main.c
   What are we doing here?
   → Shell start aaguthu inga irundhu
   → Global variables define pannurom
   → get_cmd() - command split pannurom
   → check_cmd_type() - builtin or external check
   → main() - shell loop run pannurom
   ================================================ */

/* --- Global Variables Definition --- */
char  prompt_str[MAX] = "minishell";   // default prompt
char  input_str[MAX];                   // user typed command (keep intact)
char  cmd_buf[MAX];                     // copy for strtok splitting
char *args[MAX_ARGS];                   // split arguments array
int   last_status     = 0;             // last exit status
pid_t fg_pid          = 0;             // foreground pid (0 = no child)
int   job_id          = 0;             // background job counter (Fix 3)

/* --- Stopped Jobs --- */
pid_t stopped_pid[MAX_STOP];
char  stopped_cmd[MAX_STOP][MAX];
int   stopped_c = 0;


/* ================================================
   get_cmd()
   What are we doing here?
   → "ls -l /tmp" → args[0]="ls" args[1]="-l" args[2]="/tmp"
   → cmd_buf use pannurom (input_str safe ah irukkum)
   ================================================ */
void get_cmd()
{
    char *token;
    int i = 0;

    // cmd_buf la strtok use pannurom - space base panni split
    token = strtok(cmd_buf, " \t");    // Fix 4 - space and tab handle

    while(token != NULL && i < MAX_ARGS - 1)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t");   // Fix 4 - space and tab handle
    }

    args[i] = NULL;   // execvp needs NULL at end
}


/* ================================================
   check_cmd_type()
   What are we doing here?
   → Command builtin ah external ah nu decide pannurom
   → Return BUILTIN or EXTERNAL or NO_CMD
   ================================================ */
int check_cmd_type()
{
    // args[0] NULL ah irundha no command
    if(args[0] == NULL)
        return NO_CMD;

    // Builtin commands list - shell itself handle pannanum
    if(strcmp(args[0], "cd")   == 0) return BUILTIN;
    if(strcmp(args[0], "pwd")  == 0) return BUILTIN;
    if(strcmp(args[0], "exit") == 0) return BUILTIN;
    if(strcmp(args[0], "echo") == 0) return BUILTIN;
    if(strcmp(args[0], "jobs") == 0) return BUILTIN;
    if(strcmp(args[0], "fg")   == 0) return BUILTIN;
    if(strcmp(args[0], "bg")   == 0) return BUILTIN;

    // Anything else is external command
    return EXTERNAL;
}


/* ================================================
   main()
   What are we doing here?
   → Terminal clear pannurom
   → Signals register pannurom
   → Infinite loop - shell always running
   → Prompt print → input read → process → repeat
   ================================================ */
int main()
{
    int type;

    // Clear terminal when shell starts
    system("clear");

    /* --- Register Signal Handlers ---
       What are we doing here?
       → Ctrl+C, Ctrl+Z, child finish - all catch pannurom
    */
    signal(SIGINT,  signal_handler);   // Ctrl+C
    signal(SIGTSTP, signal_handler);   // Ctrl+Z
    signal(SIGCHLD, signal_handler);   // child process finish

    /* --- Shell Infinite Loop ---
       What are we doing here?
       → Shell always ON ah irukkanum
       → while(1) illana one command run aana shell close
    */
    while(1)
    {
        /* --- Print Prompt --- */
        printf("%s> ", prompt_str);
        fflush(stdout);   // immediately display pannurom

        /* --- Read Input ---
           What are we doing here?
           → User type panna command read pannurom
           → fgets - safe way to read full line
        */
        if(fgets(input_str, MAX, stdin) == NULL)
        {
            // Ctrl+D press panna EOF comes - exit shell
            printf("\nBye!\n");
            exit(0);
        }

        // Remove newline at end
        input_str[strcspn(input_str, "\n")] = '\0';

        /* --- Empty Input Check --- */
        if(input_str[0] == '\0')
            continue;   // just show prompt again

        /* --- PS1 Prompt Change Check ---
           What are we doing here?
           → PS1=user@emertxe type pannina prompt change
           → PS1= (empty) allow pannakoodadhu
        */
        if(strncmp(input_str, "PS1=", 4) == 0)
        {
            char *new_prompt = input_str + 4;

            if(*new_prompt == '\0')
            {
                printf("Error: prompt cannot be empty!\n");
                continue;
            }

            strncpy(prompt_str, new_prompt, MAX - 1);
            prompt_str[MAX - 1] = '\0';
            continue;
        }

        /* --- Split Command into Args ---
           What are we doing here?
           → cmd_buf la copy panni get_cmd call pannurom
           → input_str safe ah irukkum (pipe check ku venum)
        */
        strncpy(cmd_buf, input_str, MAX - 1);
        cmd_buf[MAX - 1] = '\0';

        get_cmd();

        /* --- Check Command Type and Execute --- */
        type = check_cmd_type();

        if(type == NO_CMD)
            continue;

        if(type == BUILTIN)
            execute_internal_cmd();
        else
            execute_external_cmd();

    } // end while(1)

    return 0;
}

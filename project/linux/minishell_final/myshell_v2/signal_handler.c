#include "head.h"

/* ================================================
   signal_handler.c
   What are we doing here?
   → Ctrl+C press panna SIGINT catch pannurom
   → Ctrl+Z press panna SIGTSTP catch pannurom
   → Child finish aana SIGCHLD catch pannurom
   ================================================ */

void signal_handler(int sig_num)
{
    int status;

    /* ================================================
       SIGINT - Ctrl+C Handler
       What are we doing here?
       → Program running? → kill that program
       → No program? → just reprint prompt
       ================================================ */
    if(sig_num == SIGINT)
    {
        if(fg_pid == 0)
        {
            // No foreground process - just show prompt again
            printf("\n%s> ", prompt_str);
            fflush(stdout);
        }
        else
        {
            // Kill the foreground child process
            kill(fg_pid, SIGINT);
        }
    }

    /* ================================================
       SIGTSTP - Ctrl+Z Handler
       What are we doing here?
       → Program stop pannurom
       → stopped[] array la save pannurom
       → stopped_c++ count increase pannurom
       ================================================ */
    else if(sig_num == SIGTSTP)
    {
        if(fg_pid == 0)
        {
            // No foreground process - just show prompt again
            printf("\n%s> ", prompt_str);
            fflush(stdout);
        }
        else
        {
            // Stop the foreground process
            kill(fg_pid, SIGSTOP);

            // Save to stopped array
            if(stopped_c < MAX_STOP)
            {
                stopped_pid[stopped_c] = fg_pid;
                strncpy(stopped_cmd[stopped_c], input_str, MAX - 1);
                stopped_cmd[stopped_c][MAX - 1] = '\0';
                stopped_c++;
            }

            printf("\n[%d]  Stopped    %s\n", stopped_c, input_str);

            fg_pid = 0;   // No foreground child now

            // Show prompt again
            printf("%s> ", prompt_str);
            fflush(stdout);
        }
    }

    /* ================================================
       SIGCHLD - Child Finish Handler
       What are we doing here?
       → Background children finish aana reap pannurom
       → WNOHANG - dont block, just check
       ================================================ */
    else if(sig_num == SIGCHLD)
    {
        // Loop - collect all finished background children
        while(waitpid(-1, &status, WNOHANG) > 0)
        {
            // child reaped - loop continues
        }
    }
}

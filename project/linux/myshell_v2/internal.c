#include "head.h"

/* ================================================
   internal.c
   What are we doing here?
   → Builtin commands ellam inga handle pannurom
   → cd, pwd, exit, echo, jobs, fg, bg
   → Fork() panna koodadhu - shell itself run pannanum
   ================================================ */

void execute_internal_cmd()
{

    /* ================================================
       CD - Change Directory
       What are we doing here?
       → User type panna path ku directory change pannurom
       → System call: chdir()
       ================================================ */
    if(strcmp(args[0], "cd") == 0)
    {
        char *path;

        if(args[1] == NULL)
        {
            // No argument - go to HOME directory
            path = getenv("HOME");
            if(path == NULL)
                path = "/";
        }
        else
        {
            path = args[1];
        }

        if(chdir(path) < 0)
        {
            perror("cd");
            last_status = 1;
        }
        else
        {
            last_status = 0;
        }

        return;
    }


    /* ================================================
       PWD - Print Working Directory
       What are we doing here?
       → Current directory path print pannurom
       → System call: getcwd()
       ================================================ */
    if(strcmp(args[0], "pwd") == 0)
    {
        char path[MAX];

        if(getcwd(path, MAX) != NULL)
        {
            printf("%s\n", path);
            last_status = 0;
        }
        else
        {
            perror("pwd");
            last_status = 1;
        }

        return;
    }


    /* ================================================
       EXIT - Terminate Shell
       What are we doing here?
       → Shell program close pannurom
       → exit(0) call pannurom
       ================================================ */
    if(strcmp(args[0], "exit") == 0)
    {
        printf("Bye!\n");
        exit(0);
    }


    /* ================================================
       ECHO - Print Values
       What are we doing here?
       → echo $$     → shell PID print pannurom (getpid)
       → echo $?     → last command status print pannurom
       → echo $SHELL → SHELL env variable print pannurom
       → echo text   → plain text print pannurom
       ================================================ */
    if(strcmp(args[0], "echo") == 0)
    {
        if(args[1] == NULL)
        {
            printf("\n");
            return;
        }

        if(strcmp(args[1], "$$") == 0)
        {
            // $$ → minishell process ID
            printf("%d\n", (int)getpid());
        }
        else if(strcmp(args[1], "$?") == 0)
        {
            // $? → last command exit status
            printf("%d\n", last_status);
        }
        else if(strcmp(args[1], "$SHELL") == 0)
        {
            // $SHELL → SHELL environment variable
            char *sh = getenv("SHELL");
            if(sh != NULL)
                printf("%s\n", sh);
            else
                printf("/bin/minishell\n");
        }
        else
        {
            // Plain text - print all arguments
            int i = 1;
            while(args[i] != NULL)
            {
                printf("%s", args[i]);
                if(args[i + 1] != NULL)
                    printf(" ");
                i++;
            }
            printf("\n");
        }

        last_status = 0;
        return;
    }


    /* ================================================
       JOBS - List Stopped Jobs
       What are we doing here?
       → stopped[] array la irukka jobs print pannurom
       → Ctrl+Z panna jobs inga save aagum
       ================================================ */
    if(strcmp(args[0], "jobs") == 0)
    {
        int i;

        if(stopped_c == 0)
        {
            printf("No stopped jobs\n");
        }
        else
        {
            for(i = 0; i < stopped_c; i++)
            {
                printf("[%d]  Stopped    pid=%-6d  %s\n",
                       i + 1,
                       (int)stopped_pid[i],
                       stopped_cmd[i]);
            }
        }

        last_status = 0;
        return;
    }


    /* ================================================
       FG - Bring Job to Foreground
       What are we doing here?
       → Stopped job va foreground la kondu varurom
       → SIGCONT send pannurom → process resume aagum
       → waitpid WUNTRACED - Ctrl+Z again handle pannurom
       ================================================ */
    if(strcmp(args[0], "fg") == 0)
    {
        int status;

        if(stopped_c == 0)
        {
            printf("fg: No stopped jobs\n");
            last_status = 1;
            return;
        }

        // Get last stopped job
        stopped_c--;
        fg_pid = stopped_pid[stopped_c];

        // Fix: Save real command name into input_str
        // so signal_handler saves correct name when Ctrl+Z pressed
        strncpy(input_str, stopped_cmd[stopped_c], MAX - 1);
        input_str[MAX - 1] = '\0';

        printf("%s\n", input_str);

        // Send SIGCONT - resume the stopped process
        kill(fg_pid, SIGCONT);

        // Wait - WUNTRACED means return if Ctrl+Z pressed again
        waitpid(fg_pid, &status, WUNTRACED);

        // Fix: Remove double save here
        // signal_handler already saved it when Ctrl+Z was pressed
        // We only update last_status here
        if(WIFEXITED(status))
        {
            last_status = WEXITSTATUS(status);
        }

        fg_pid = 0;
        return;
    }


    /* ================================================
       BG - Resume Job in Background
       What are we doing here?
       → Stopped job va background la resume pannurom
       → SIGCONT send pannurom → wait pannama continue
       ================================================ */
    if(strcmp(args[0], "bg") == 0)
    {
        if(stopped_c == 0)
        {
            printf("bg: No stopped jobs\n");
            last_status = 1;
            return;
        }

        // Get last stopped job
        stopped_c--;

        printf("[%d]  %d  %s &\n",
               stopped_c + 1,
               (int)stopped_pid[stopped_c],
               stopped_cmd[stopped_c]);

        // Send SIGCONT - resume in background
        kill(stopped_pid[stopped_c], SIGCONT);

        last_status = 0;
        return;
    }
}

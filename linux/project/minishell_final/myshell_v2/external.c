#include "head.h"

/* ================================================
   external.c
   What are we doing here?
   → External commands handle pannurom (ls, date, sleep)
   → N-pipe implement pannurom (ls | grep | wc)
   → Background process handle pannurom (sleep 10 &)
   ================================================ */


/* ================================================
   run_pipe()
   What are we doing here?
   → ls | grep .c | wc -l → 3 commands, 2 pipes
   → Each command ku fork pannurom
   → dup2 use panni stdin/stdout connect pannurom
   → execvp use panni each command run pannurom
   ================================================ */
void run_pipe(char *input)
{
    char *segments[MAX_PIPE];    // Fix 3 - MAX_PIPE use pannurom
    int   seg_count = 0;
    int   fd[MAX_PIPE][2];       // pipe file descriptors
    char  buf[MAX];
    int   i;

    /* --- Split Input by Pipe Symbol --- */
    strncpy(buf, input, MAX - 1);
    buf[MAX - 1] = '\0';

    char *tok = strtok(buf, "|");
    while(tok != NULL && seg_count < MAX_PIPE - 1)
    {
        // Remove leading spaces
        while(*tok == ' ' || *tok == '\t') tok++;
        segments[seg_count] = tok;
        seg_count++;
        tok = strtok(NULL, "|");
    }

    /* --- Create (N-1) Pipes ---
       What are we doing here?
       → 3 commands = 2 pipes venum
       → pipe() → fd[0]=read end, fd[1]=write end
    */
    for(i = 0; i < seg_count - 1; i++)
    {
        if(pipe(fd[i]) < 0)
        {
            perror("pipe");
            return;
        }
    }

    /* --- Fork One Child Per Command --- */
    for(i = 0; i < seg_count; i++)
    {
        pid_t cpid = fork();

        if(cpid < 0)
        {
            perror("fork");
            return;
        }

        if(cpid == 0)
        {
            /* --- Child Process ---
               What are we doing here?
               → stdin wire pannurom (previous pipe read end)
               → stdout wire pannurom (current pipe write end)
               → execvp use panni command run pannurom
            */

            // Restore default signals in child
            signal(SIGINT,  SIG_DFL);
            signal(SIGTSTP, SIG_DFL);
            signal(SIGCHLD, SIG_DFL);

            // Connect stdin to previous pipe (except first command)
            if(i > 0)
            {
                if(dup2(fd[i-1][0], STDIN_FILENO) < 0)
                {
                    perror("dup2 stdin");
                    exit(1);
                }
            }

            // Connect stdout to current pipe (except last command)
            if(i < seg_count - 1)
            {
                if(dup2(fd[i][1], STDOUT_FILENO) < 0)
                {
                    perror("dup2 stdout");
                    exit(1);
                }
            }

            // Close all pipe fds in child
            int j;
            for(j = 0; j < seg_count - 1; j++)
            {
                close(fd[j][0]);
                close(fd[j][1]);
            }

            // Parse this segment into args
            char *seg_args[MAX_ARGS];
            char  seg_buf[MAX];
            int   arg_count = 0;    // Fix 8 - better variable name

            strncpy(seg_buf, segments[i], MAX - 1);
            seg_buf[MAX - 1] = '\0';

            char *t = strtok(seg_buf, " \t");   // Fix 4 - space and tab
            while(t != NULL && arg_count < MAX_ARGS - 1)
            {
                seg_args[arg_count] = t;
                arg_count++;
                t = strtok(NULL, " \t");
            }
            seg_args[arg_count] = NULL;

            /* Fix 5 - Empty command check
               What are we doing here?
               → "ls | | wc" → middle command empty crash aagalam
               → NULL check pannurom
            */
            if(seg_args[0] == NULL)
                exit(0);

            // Run the command
            if(execvp(seg_args[0], seg_args) < 0)
            {
                fprintf(stderr, "%s: command not found\n", seg_args[0]);
                exit(1);
            }
        }
        // Parent continues to fork next child
    }

    /* --- Parent: Close All Pipes --- */
    for(i = 0; i < seg_count - 1; i++)
    {
        close(fd[i][0]);
        close(fd[i][1]);
    }

    /* --- Parent: Wait for All Children ---
       Fix 1 - wait() instead of waitpid() use pannurom
       waitpid(-1) → any child wait pannurom
    */
    int status;
    for(i = 0; i < seg_count; i++)
    {
        waitpid(-1, &status, 0);    // Fix 1 - waitpid instead of wait
    }

    /* Fix 2 - Correct last_status logic
       What are we doing here?
       → Command success? → exit status save pannurom
       → Signal kill? → 128 + signal number save pannurom
    */
    if(WIFEXITED(status))
        last_status = WEXITSTATUS(status);
    else if(WIFSIGNALED(status))
        last_status = 128 + WTERMSIG(status);
}


/* ================================================
   execute_external_cmd()
   What are we doing here?
   → Pipe irukka? → run_pipe() call pannurom
   → Background (&) irukka? → wait pannama continue
   → Normal command → fork + execvp + waitpid
   ================================================ */
void execute_external_cmd()
{
    int status;
    int is_bg    = 0;   // background flag
    int arg_count = 0;  // Fix 8 - better variable name

    /* --- Count Arguments --- */
    while(args[arg_count] != NULL)
        arg_count++;

    /* --- Background Check ---
       What are we doing here?
       → "sleep 10 &" → last arg is "&"
       → & remove pannurom, is_bg = 1 set pannurom
    */
    if(arg_count > 0 && strcmp(args[arg_count - 1], "&") == 0)
    {
        is_bg = 1;
        args[arg_count - 1] = NULL;
        arg_count--;
    }

    /* --- Pipe Check --- */
    if(strchr(input_str, '|') != NULL)
    {
        run_pipe(input_str);
        return;
    }

    /* --- Single External Command ---
       What are we doing here?
       → fork() → child process create pannurom
       → Child: execvp() → command run pannurom
       → Parent: waitpid() → child finish wait pannurom
    */
    fg_pid = fork();

    if(fg_pid < 0)
    {
        perror("fork");
        return;
    }

    if(fg_pid == 0)
    {
        /* --- Child Process --- */

        // Restore default signals in child
        signal(SIGINT,  SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        signal(SIGCHLD, SIG_DFL);

        // Run the command
        if(execvp(args[0], args) < 0)
        {
            fprintf(stderr, "%s: command not found\n", args[0]);
            exit(127);
        }
    }
    else
    {
        /* --- Parent Process --- */

        if(is_bg)
        {
            /* --- Background Job ---
               Fix 3 - job_id increment pannurom
               → [1], [2], [3] correct ah show aagum
            */
            job_id++;
            printf("[%d] %d\n", job_id, (int)fg_pid);
            fg_pid = 0;   // Shell not waiting
        }
        else
        {
            /* --- Foreground Job ---
               What are we doing here?
               → Child finish aagura varaikkum wait pannurom
               → WUNTRACED → Ctrl+Z panna also return aagum
            */
            waitpid(fg_pid, &status, WUNTRACED);

            /* Fix 2 - Correct last_status
               What are we doing here?
               → Normal exit? → exit code save pannurom
               → Stopped? → status = 0
               → Signal killed? → 128 + signal
            */
            if(WIFEXITED(status))
                last_status = WEXITSTATUS(status);
            else if(WIFSTOPPED(status))
                last_status = 0;
            else if(WIFSIGNALED(status))
                last_status = 128 + WTERMSIG(status);

            fg_pid = 0;   // No foreground child now
        }
    }
}

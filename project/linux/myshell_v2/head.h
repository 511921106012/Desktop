#ifndef HEAD_H
#define HEAD_H

/* ================================================
   head.h
   What are we doing here?
   → All files ku common items inga irukku
   → Like a shared toolbox for all .c files
   ================================================ */

/* --- Standard Header Files --- */
#include <stdio.h>       // printf, scanf use panna
#include <stdlib.h>      // exit(), getenv() use panna
#include <string.h>      // strcmp, strcpy use panna
#include <unistd.h>      // fork, execvp, chdir use panna
#include <signal.h>      // signal handling use panna
#include <sys/wait.h>    // waitpid use panna
#include <sys/types.h>   // pid_t use panna

/* --- Macros --- */
#define MAX       1024   // input string max size
#define MAX_ARGS  64     // max arguments count
#define MAX_STOP  32     // max stopped jobs
#define MAX_PIPE  16     // max pipe segments (Fix 3 - safer size)

/* --- Command Type Macros --- */
#define BUILTIN   1      // cd, pwd, exit, echo, jobs, fg, bg
#define EXTERNAL  2      // ls, date, sleep - any program
#define NO_CMD    3      // empty input

/* ================================================
   Global Variables
   What are we doing here?
   → Ella files use panna common variables
   → extern means "defined in main.c"
   ================================================ */
extern char  prompt_str[MAX];          // shell prompt store panna
extern char  input_str[MAX];           // user type panna command
extern char  cmd_buf[MAX];             // get_cmd ku use panna copy
extern char *args[MAX_ARGS];           // split command arguments
extern int   last_status;              // last command exit status
extern pid_t fg_pid;                   // foreground process pid
extern int   job_id;                   // background job counter (Fix 3)

/* --- Stopped Jobs Array --- */
extern pid_t stopped_pid[MAX_STOP];        // stopped process pids
extern char  stopped_cmd[MAX_STOP][MAX];   // stopped process commands
extern int   stopped_c;                    // stopped jobs count

/* ================================================
   Function Prototypes
   What are we doing here?
   → All function names declare pannurom
   → So all files can call each other
   ================================================ */

// main.c
void get_cmd();
int  check_cmd_type();

// signal_handler.c
void signal_handler(int sig_num);

// internal.c
void execute_internal_cmd();

// external.c
void execute_external_cmd();

#endif

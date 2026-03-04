#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc < 4) {
        printf("Error: No arguments passed, Provide at least one pipe\n");
        printf("Usage: ./pipe <command1> '|' <command2> ...\n");
        return 1;
    }

    int pipe_count = 0;

    // Count number of pipes
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0)
            pipe_count++;
    }

    if (pipe_count == 0) {
        printf("Error: At least one pipe required\n");
        return 1;
    }

    int cmd_count = pipe_count + 1;
    int pipefd[pipe_count][2];

    // Create pipes
    for (int i = 0; i < pipe_count; i++) {
        if (pipe(pipefd[i]) == -1) {
            perror("pipe");
            exit(1);
        }
    }

    int cmd_start = 1;

    for (int i = 0; i < cmd_count; i++) {

        int j = cmd_start;

        // Find next "|"
        while (j < argc && strcmp(argv[j], "|") != 0)
            j++;

        argv[j] = NULL;   // separate command for execvp

        pid_t pid = fork();

        if (pid == 0) {  // child

            // First command
            if (i == 0) {
                dup2(pipefd[i][1], STDOUT_FILENO);
            }
            // Last command
            else if (i == cmd_count - 1) {
                dup2(pipefd[i-1][0], STDIN_FILENO);
            }
            // Middle command
            else {
                dup2(pipefd[i-1][0], STDIN_FILENO);
                dup2(pipefd[i][1], STDOUT_FILENO);
            }

            // Close all pipe ends
            for (int k = 0; k < pipe_count; k++) {
                close(pipefd[k][0]);
                close(pipefd[k][1]);
            }

            execvp(argv[cmd_start], &argv[cmd_start]);
            perror("execvp failed");
            exit(1);
        }

        cmd_start = j + 1;
    }

    // Parent closes all pipes
    for (int i = 0; i < pipe_count; i++) {
        close(pipefd[i][0]);
        close(pipefd[i][1]);
    }

    // Wait for all children
    for (int i = 0; i < cmd_count; i++)
        wait(NULL);

    return 0;
}
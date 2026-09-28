#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#include "../include/process.h"

int execute(char **tokens)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        /* Restore default signal handling in child */
        signal(SIGINT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);

        if (execvp(tokens[0], tokens) == -1)
        {
            perror("Mini Bash Clone");
        }

        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        /* Wait for foreground child */
        while (1)
        {
            pid_t result = waitpid(pid, &status, WUNTRACED);

            if (result == pid)
            {
                break;
            }

            if (result == -1 && errno == EINTR)
            {
                continue;
            }

            if (result == -1 && errno == ECHILD)
            {
                break;
            }

            if (result == -1)
            {
                perror("waitpid");
                break;
            }
        }
    }

    return 1;
}

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

#include "../include/signals.h"

/* Handle Ctrl+C */
void sigint_handler(int sig)
{
    (void)sig;

    printf("\nMini Bash Clone: Press 'exit' to quit.\n");
}

/* Handle completed child processes */
void sigchld_handler(int sig)
{
    (void)sig;

    while (waitpid(-1, NULL, WNOHANG) > 0)
    {
        /* Reap finished child processes */
    }
}

/* Initialize signal handlers */
void initialize_signals(void)
{
    signal(SIGINT, sigint_handler);
    signal(SIGCHLD, sigchld_handler);
}

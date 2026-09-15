#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/shell.h"
#include "../include/input.h"
#include "../include/parser.h"
#include "../include/process.h"
#include "../include/builtin.h"

int main()
{
    char *line;
    char **tokens;

    printf("=====================================\n");
    printf("Mini Bash Clone - Version 5.0\n");
    printf("=====================================\n");

    while (1)
    {
        printf("myshell> ");

        line = read_line();

        tokens = parse_line(line);

        if (tokens[0] != NULL)
        {
            if (execute_builtin(tokens) == 0)
            {
                execute(tokens);
            }
        }

        free_tokens(tokens);
        free(line);
    }

    return 0;
}


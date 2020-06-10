#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>

#include "config.h"

int main(int argc, char **argv)
{
    printf("My Own Lisp v%s\n", MOL_VERSION);
    printf("Press Ctrl+C to Exit\n\n");

    while (1) {
        char *input = readline(MOL_PROMPT);
        add_history(input);

        printf("No, you are a %s\n", input);

        free(input);
    }
}

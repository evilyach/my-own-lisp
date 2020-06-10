#include <stdio.h>

#include "config.h"

int main(int argc, char **argv)
{
    printf("My Own Lisp v%s\n", MOL_VERSION);
    printf("Press Ctrl+C to Exit\n\n");

    while (1) {
        fputs("my-own-lisp > ", stdout);
        fgets(input, INPUT_SIZE, stdin);
        printf("No, you are a %s", input);
    }
}
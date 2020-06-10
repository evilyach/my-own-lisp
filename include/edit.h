#ifndef EDIT_H
#define EDIT_H

#ifdef _WIN32
    #include <string.h>
    #define BUFFER_SIZE 2048

    static char buffer[BUFFER_SIZE];

    /* Fake readline function */
    char* readline(char* prompt)
    {
        fputs(prompt, stdout);
        fgets(buffer, BUFFER_SIZE, stdin);

        char* copy = malloc(strlen(buffer) + 1);
        strcpy(copy, buffer);
        copy[strlen(cpy) - 1] = '\0';

        return copy;
    }

    /* Fake add_history function */
    void add_history(char* unused) {}
#else
    #include <editline/readline.h>
#endif

#endif /* EDIT_H */

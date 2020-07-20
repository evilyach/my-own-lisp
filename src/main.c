#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "edit.h"
#include "parser.h"

int main(int argc, char **argv)
{
    printf("My Own Lisp v%s\n", MOL_VERSION);
    printf("Press Ctrl+C to Exit\n\n");

    mpc_parser_t *number = mpc_new("number");
    mpc_parser_t *operator = mpc_new("operator");
    mpc_parser_t *expression = mpc_new("expression");
    mpc_parser_t *lisp = mpc_new("lisp");

    mpca_lang(
        MPCA_LANG_DEFAULT, MOL_LANGUAGE_RULES,
        number, operator, expression, lisp
    );

    while (1) {
        char *input = readline(MOL_PROMPT);
        add_history(input);

        mpc_result_t result;
        if (mpc_parse("<stdin>", input, lisp, &result)) {
            mpc_ast_print(result.output);
            mpc_ast_delete(result.output);
        } else {
            mpc_err_print(result.error);
            mpc_err_delete(result.error);
        }

        free(input);
    }

    mpc_cleanup(4, number, operator, expression, lisp);
}

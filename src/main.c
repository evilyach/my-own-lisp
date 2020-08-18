#include <stdio.h>
#include <stdlib.h>

#include "../lib/mpc.h"
#include "config.h"
#include "edit.h"
#include "evaluation.h"
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

        mpc_result_t mpc_result;
        if (mpc_parse("<stdin>", input, lisp, &mpc_result)) {
            long result = evaluate(mpc_result.output);
            printf("%li\n", result);

            mpc_ast_delete(mpc_result.output);
        } else {
            mpc_err_print(mpc_result.error);
            mpc_err_delete(mpc_result.error);
        }

        free(input);
    }

    mpc_cleanup(4, number, operator, expression, lisp);
}

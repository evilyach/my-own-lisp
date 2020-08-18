#include "evaluation.h"

long evaluate(ast_t *tree)
{
    /* If tag is number, return it */
    if (strstr(tree->tag, "number")) {
        return atoi(tree->contents);
    }

    /* Child is always a second child, and 'x' - the third one */
    char *op = tree->children[1]->contents;
    char x = evaluate(tree->children[2]);

    /* Iterate through the remaining children */
    for (int i = 3; strstr(tree->children[i]->tag, "expr"); i++) {
        x = evaluate_op(x, op, evaluate(tree->children[i]));
    }

    return x;
}

long evaluate_op(long x, char *op, long y) {
    if (!strcmp(op, "+")) {
        return x + y;
    }

    if (!strcmp(op, "-")) {
        return x - y;
    }

    if (!strcmp(op, "*")) {
        return x * y;
    }

    if (!strcmp(op, "/")) {
        return x / y;
    }

    return 0;
}

#ifndef PARSER_H
#define PARSER_H

#include "../lib/mpc.h"

const char *MOL_LANGUAGE_RULES = " \
    number     : /-?[0-9]+/ ; \
    operator   : '+' | '-' | '*' | '/' ; \
    expression : <number> | '(' <operator> <expression>+ ')' ; \
    lisp       : /^/ <operator> <expression>+ /$/ ; \
";

#endif /* PARSER_H */

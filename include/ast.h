#ifndef AST_H
#define AST_H

#include "../lib/mpc.h"

/**
 * Abstract Syntax Tree structure.
 * 
 * This is a AST data structure we got from the parse.
 */
typedef struct ast_t {
    /*
     * String containing a list of all the rules used to parse that particular
     * item.
     *
     * For example:
     * regex
     * expression|number|regex
     */
    char *tag;

    /*
     * Actual contents of the node.
     */
    char *contents;

    /*
     * Information about what state the parser was in when it found thos node,
     * such as the line and column number.
     */
    mpc_state_t state;

    /*
     * The amount of children this node has.
     */
    int children_count;

    /*
     * Array of children of this node.
     */
    struct ast_t **children;
} ast_t;

#endif /* AST_H */

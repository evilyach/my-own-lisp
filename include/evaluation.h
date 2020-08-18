#ifndef EVALUATION_H
#define EVALUATION_H

#include "ast.h"

/**
 * Evaluate and accumulate the result.
 * 
 * @tree ast - AST struct.
 * 
 * @return - the result of evaluation.
 */
long evaluate(ast_t *tree);

/**
 * Evaluate the arithmetic operation.
 * 
 * @x - the first operand.
 * @op - operation ("+", "-", "/", "*")
 * @y - the second operand.
 * 
 * @return - the result of evaluation.
 */
long evaluate_op(long x, char *op, long y);

#endif /* EVALUATION_H */

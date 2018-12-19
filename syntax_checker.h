// Carapcea Andrei-Antonio 313CD
#ifndef SYNTAX_CHECKER_H
#define SYNTAX_CHECKER_H
#include "utils.h"

/* Check for syntax errors in op.
 * Parameters:
 * op : command
 * min_warp : should be the length of the longest word in input file
 * Return :
 * -1 for a syntax error in an op.
 * -2 if a wrap length is smaller than min_warp.
 */
int syntax_check(char op[MAX_COMMAND_LENGTH], int min_warp);

#endif

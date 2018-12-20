#ifndef PARSER_H
#define PARSER_H
#include "utils.h"

/* Parses op and applies specific operation
 * Parameters :
 * op - operation to do
 * result - array of lines on which to do the op.
 * *result_line_count - pointer to no. lines in result
 * Note : modifies result_line_count.
 */
void parse(char op[MAX_ARGS * MAX_ARG_LENGTH],
           char result[MAX_LINES][MAX_CHARS_PER_LINE], int *result_line_count);

#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "parser.h"
#include "align_left.h"
#include "align_right.h"
#include "center.h"
#include "justify.h"
#include "paragraph.h"
#include "wrap.h"
#include "list.h"
#include "ordered_list.h"
#include "utils.h"

/* Get [start_line [end_line]]
 * Modifies parameters start_line and end_line
 * args - array of arguments
 * arg_counter - index at which to start looking for args.
 * Needs result_line_count for setting the apropriate value of end_line
 */
void get_interval(char args[MAX_ARGS][MAX_ARG_LENGTH],
                  int argc, int arg_counter, int *start_line, int *end_line,
                  int result_line_count)
{
    *start_line = 0;
    *end_line = result_line_count - 1;
    if(arg_counter < argc) {
        *start_line = toNumber(args[arg_counter++]);
    }
    if(arg_counter < argc) {
        *end_line = toNumber(args[arg_counter++]);
    }
    if(*end_line > result_line_count)
        *end_line = result_line_count;
}

void parse(char op[MAX_ARGS * MAX_ARG_LENGTH],
           char result[MAX_LINES][MAX_CHARS_PER_LINE], int *result_line_count)
{
    char args[MAX_ARGS][MAX_ARG_LENGTH], list_type, special_character,
         ordering;
    int argc = 0, max_line_length, indent_length, start_line, end_line;

    char *c = strtok(op + 1, " "); // Tokenize operation
    while(c != NULL) {
        strcpy(args[argc++], c);
        c = strtok(NULL, " ");
    }
    op[0] = tolower(op[0]);
    switch(op[0]) {
    case 'w':
        max_line_length = toNumber(args[0]);
        wrap(max_line_length, result, result_line_count);
        break;
    case 'c':
        get_interval(args, argc, 0, &start_line, &end_line,
                     *result_line_count);
        center(start_line, end_line, result, *result_line_count);
        break;
    case 'l':
        get_interval(args, argc, 0, &start_line, &end_line,
                     *result_line_count);
        align_left(start_line, end_line, result);
        break;
    case 'r':
        get_interval(args, argc, 0, &start_line, &end_line,
                     *result_line_count);
        align_right(start_line, end_line, result, *result_line_count);
        break;
    case 'j':
        get_interval(args, argc, 0, &start_line, &end_line,
                     *result_line_count);
        justify(start_line, end_line, result, *result_line_count);
        break;
    case 'p':
    case 'P':
        indent_length = toNumber(args[0]);
        get_interval(args, argc, 1, &start_line, &end_line,
                     *result_line_count);
        paragraph(indent_length, start_line, end_line, result);
        break;
    case 'i':
        list_type = args[0][0];
        special_character = args[1][0];
        get_interval(args, argc, 2, &start_line, &end_line,
                     *result_line_count);
        list(list_type, special_character, start_line, end_line, result);
        break;
    case 'o':
        list_type = args[0][0];
        special_character = args[1][0];
        ordering = args[2][0];
        get_interval(args, argc, 3, &start_line, &end_line,
                     *result_line_count);
        ordered_list(list_type, special_character, ordering, start_line,
                     end_line, result);
        break;
    }
    return;
}

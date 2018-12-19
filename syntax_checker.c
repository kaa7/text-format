#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "syntax_checker.h"
#include "utils.h"


/* check syntax errors for [start_line [end_line]]
 * argc = total no. args
 * arg_counter = index at which to start looking for args
 * returns -1 for error and 0 otherwise
 */
int check_interval(char args[MAX_ARGS][MAX_ARG_LENGTH],
                   int argc, int arg_counter)
{
    if(arg_counter > argc)
        return -1;
    int start_line, end_line;
    if(arg_counter < argc) {
        start_line = toNumber(args[arg_counter++]);
        if(start_line == -1) {
            return -1;
        }
    }
    if(arg_counter < argc) {
        end_line = toNumber(args[arg_counter++]);
        if(end_line < start_line) {
            return -1;
        }
    }
    return 0;
}

/* check syntax errors for list_type and special_character
 * argc = total no. args
 * arg_counter = index at which to start looking for args
 * returns -1 for error and 0 otherwise
 */
int check_list(char args[MAX_ARGS][MAX_ARG_LENGTH], int argc, int arg_counter)
{
    if(arg_counter >= argc)
        return -1;
    char list_type = args[arg_counter++][0];
    if(list_type != 'n' && list_type != 'a' && list_type != 'A'
            && list_type != 'b')
        return -1;
    if(arg_counter >= argc)
        return -1;
    return 0;
}

int syntax_check(char op_original[MAX_ARGS * MAX_ARG_LENGTH], int min_warp)
{
    if(strlen(op_original) > MAX_COMMAND_LENGTH)
        return -1;

    char op[MAX_ARGS * MAX_ARG_LENGTH], args[MAX_ARGS][MAX_ARG_LENGTH],
         ordering;
    int argc = 0, max_line_length, indent_length;

    remove_extra_whitespace(op_original); // Makes it easier to work with op
    strcpy(op, op_original);

    char *c = strtok(op + 1, " "); // Tokenize operation string
    while(c != NULL) {
        strcpy(args[argc++], c);
        c = strtok(NULL, " ");
    }
    op[0] = tolower(op[0]);
    switch(op[0]) {
    case 'w':
        if(argc != 1) {
            return -1;
        }
        max_line_length = toNumber(args[0]);
        if(max_line_length == -1) {
            return -1;
        }
        if(max_line_length < min_warp) { // If wrap is too big
            return -2;
        }
        break;
    case 'c':
    case 'l':
    case 'r':
    case 'j':
        if(argc > 2) {
            return -1;
        }
        return check_interval(args, argc, 0);
    case 'p':
        if(argc < 1 || argc > 3)
            return -1;
        indent_length = toNumber(args[0]);
        if(indent_length == -1 || indent_length > 8)
            return -1;
        return check_interval(args, argc, 1);
    case 'i':
        if(argc < 2 || argc > 4)
            return -1;
        if(check_list(args, argc, 0))
            return -1;
        return check_interval(args, argc, 2);
    case 'o':
        if(argc < 3 || argc > 5)
            return -1;
        if(check_list(args, argc, 0))
            return -1;
        ordering = args[2][0];
        if(!(ordering == 'a' || ordering == 'z'))
            return -1;
        return check_interval(args, argc, 3);
    default:
        return -1;
    }
    return 0;
}

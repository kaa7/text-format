// Carapcea Andrei-Antonio 313CD
#ifndef UTILS_H
#define UTILS_H

#define MAX_ARG_LENGTH 5 // maximum length of a command argument
#define MAX_ARGS 5 // maximum no. of arguments
#define MAX_COMMAND_LENGTH 20
#define DELIMITERS ",\t"
#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 1000
#define MAX_NO_OPS 10

void remove_extra_whitespace(char *str);

int toNumber(char *str);

int get_max_word_length(char str[MAX_LINES][MAX_CHARS_PER_LINE],
                        int line_count);

void remove_trailing_whitespace(char *str);
void remove_starting_whitespace(char **str);
int get_max_line_len(char result[MAX_LINES][MAX_CHARS_PER_LINE],
                     int result_line_count);

/* Shift string to the right by amount.
 * Inserts space at the beginning
 */
void shift_right(char *str, int amount);

int cmp_string_incr(const void *a, const void *b);

int cmp_string_decr(const void *a, const void *b);

#endif

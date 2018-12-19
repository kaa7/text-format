#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void remove_starting_whitespace(char **str) {
    char *end = *str + strlen(*str);
    while(isspace(**str) && *str != end ) {
        ++(*str);
    }
}

void remove_extra_whitespace(char *str) {
	int i = 0, j = 0;
	if(str[i] != ' ')
		str[j++]=str[i];
	++i;
	for(; str[j] && str[i] && i < 20; ++i) {
		if(str[i] != ' ' || str[i - 1] != ' ') {
			str[j++]=str[i];
		}
	}
	str[j]='\0';
}

/* converts a string to a natural number
 * if the string isn't a natural number returns -1
 */
int toNumber(char *str) {
	if(str == NULL || *str == '\0' || *str == ' ')
		return -1;
	int i, number = 0;
	for(i = 0; i < strlen(str); ++i) {
		if(str[i] < '0' || str[i] > '9')
			return -1;
		number = number * 10 + str[i] - '0';
	}
	return number;
}

int get_max_word_length(char original[MAX_LINES][MAX_CHARS_PER_LINE], int line_count) {
	int i, max = 0;
	// make copy of original to not modify it
	char str[MAX_LINES][MAX_CHARS_PER_LINE];
	char *ptr;
	for(i = 0; i < line_count; ++i) {
		strcpy(str[i],original[i]);
		ptr = strtok(str[i]," ");
		while(ptr != NULL) {
			int length = strlen(ptr);
			if(length > max) {
				max = length;
			}
			ptr = strtok(NULL, " ");
		}
	}
	return max;
}

void remove_trailing_whitespace(char *str) {
    char *end = str + strlen(str) - 1;
    while( end > str && isspace(*end) ) {
        end --;
    }
    if(isspace(*end))
        *end = '\0';
    else
    *(end + 1) = '\0';
}

int get_max_line_len(char result[MAX_LINES][MAX_CHARS_PER_LINE],
        int result_line_count)
{
    int i, max_len = 0;
    for(i = 0; i < result_line_count; ++i) {
        int line_len = strlen(result[i]);
        if(line_len > max_len) {
            max_len = line_len;
        }
    }
    return max_len;
}

void shift_right(char *str, int amount)
{
    int j, len = strlen(str);
    memmove(str + amount, str, sizeof(char)*len);
    str[len + amount] = '\0';
    for(j = 0; j < amount; ++j) {
        str[j] = ' ';
    }
}

int cmp_string_incr(const void *a, const void *b) {
    const char *_a = (const char*)a;
    const char *_b = (const char*)b;
    return strcmp(_a, _b);
}

int cmp_string_decr(const void *a, const void *b) {
    const char *_a = (const char*)a;
    const char *_b = (const char*)b;
    return strcmp(_b, _a);
}

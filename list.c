#include <stdio.h>
#include <string.h>
#include "list.h"
#include "utils.h"
#include "align_left.h"

void list(char list_type, char special_character, int start_line,
          int end_line, char result[MAX_LINES][MAX_CHARS_PER_LINE])
{
    int i, shift_amount;
    char number[3]; // used to store string representation of a number
    align_left(start_line, end_line, result);
    switch(list_type) {
    case 'b':
        for(i = start_line; i <= end_line; ++i) {
            shift_amount = 2;
            // If line is empty, don't add trailing whitespace
            if(strlen(result[i]) == 0) {
                --shift_amount;
            }
            shift_right(result[i], shift_amount);
            result[i][0] = special_character;
        }
        break;
    case 'n': {
        int number_len;
        for(i = start_line; i <= end_line; ++i) {
            // Convert number to string
            sprintf(number, "%d", i - start_line + 1);
            number_len = strlen(number);

            shift_amount = number_len + 2;
            // If line is empty, don't add trailing whitespace
            if(strlen(result[i]) == 0)
                --shift_amount;

            shift_right(result[i], shift_amount);
            strncpy(result[i], number, number_len);
            result[i][number_len] = special_character;
        }
        break;
    }
    case 'a':
        for(i = start_line; i <= end_line; ++i) {
            shift_amount = 3;
            // If line is empty, don't add trailing whitespace
            if(strlen(result[i]) == 0) {
                --shift_amount;
            }
            shift_right(result[i], shift_amount);
            result[i][0] = 'a' + i - start_line;
            result[i][1] = special_character;
        }
        break;
    case 'A':
        for(i = start_line; i <= end_line; ++i) {
            shift_amount = 3;
            // If line is empty, don't add trailing whitespace
            if(strlen(result[i]) == 0) {
                --shift_amount;
            }
            shift_right(result[i], shift_amount);
            result[i][0] = 'A' + i - start_line;
            result[i][1] = special_character;
        }
    }
}

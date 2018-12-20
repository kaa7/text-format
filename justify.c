#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "justify.h"
#include "utils.h"
#include "align_left.h"

void justify(int start_line, int end_line,
             char result[MAX_LINES][MAX_CHARS_PER_LINE],
             int result_line_count)
{
    int i, max_line_len = get_max_line_len(result, result_line_count);

    align_left(start_line, end_line, result);

    for(i = start_line; i <= end_line; ++i) {
        if(i + 1 <= end_line) { // If next line is still in the interval
            if(strlen(result[i + 1]) == 0) { // Do nothing at end of paragraph
                ++i;
                continue;
            }
        }

        int no_spaces = 0, j = 0, prev = 0,
            diff = max_line_len - strlen(result[i]);
        char words[MAX_CHARS_PER_LINE][MAX_CHARS_PER_LINE]; // Store words
        while(j < strlen(result[i])) { // Count no. spaces and tokenize words
            while(!isspace(result[i][j])) {
                ++j;
            }
            while(isspace(result[i][j])) {
                ++j;
            }
            sprintf(words[no_spaces++], "%.*s", j - prev, result[i] + prev);
            prev = j;
        }
        --no_spaces; // don't add spaces at the end to keep right alignment
        for(j = 0; j < no_spaces; ++j) {
            int added_spaces = 0;
            // distribute spaces evenly
            while(diff / no_spaces - added_spaces++ > 0) {
                strcat(words[j], " ");
            }
            if(j < diff % no_spaces)
                strcat(words[j], " ");
        }
        result[i][0] = '\0';
        for(j = 0; j < no_spaces + 1; ++j) {
            strcat(result[i], words[j]);
        }
    }
}

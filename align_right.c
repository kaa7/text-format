#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "align_right.h"

void align_right(int start_line, int end_line,
                 char result[MAX_LINES][MAX_CHARS_PER_LINE],
                 int result_line_count)
{
    int i, max_line_len = get_max_line_len(result, result_line_count);
    for(i = start_line; i <= end_line; ++i) {
        // If line is empty do nothing
        if(result[i][0] == '\0')
            continue;
        // Calculate no. spaces that need to be added
        int diff = max_line_len - strlen(result[i]);
        if(diff > 0) {
            shift_right(result[i], diff);
        }
    }
}

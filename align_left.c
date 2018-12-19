#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "align_left.h"
#include "utils.h"

void align_left(int start_line, int end_line,
                char result[MAX_LINES][MAX_CHARS_PER_LINE])

{
    int i;
    for(i = start_line; i <= end_line; ++i) {
        char *p = result[i];
        // Skip starting whitespace
        while(isspace(*p))
            ++p;
        // If line is empty, do nothing
        if(*p == 0)
            continue;
        // Align line to the left
        int len = strlen(p);
        memmove(result[i], p, sizeof(char)*len);
        result[i][len] = '\0';
    }
}

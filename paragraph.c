#include <string.h>
#include "paragraph.h"
#include "utils.h"
#include "align_left.h"

void paragraph(int indent_length, int start_line, int end_line,
               char result[MAX_LINES][MAX_CHARS_PER_LINE])
{
    int i = start_line;
    // Skip if start_line is in a paragraph but not at the beginning
    if(i > 0) {
        if(strlen(result[i - 1]) != 0) {
            ++i;
            while(strlen(result[i]) != 0 && i <= end_line) {
                ++i;
            }
        }
    }
    for(; i <= end_line; ++i) {
        // If a begining of a paragraph is found
        if(strlen(result[i]) != 0) {
            align_left(i, i, result);
            shift_right(result[i++], indent_length); // indent
            // Skip rest of the paragraph
            while(strlen(result[i]) != 0 && i <= end_line) {
                ++i;
            }
        }
    }
}

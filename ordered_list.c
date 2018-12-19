#include <stdlib.h>
#include "ordered_list.h"
#include "list.h"
#include "utils.h"


void ordered_list(char list_type, char special_character, char ordering,
                  int start_line, int end_line,
                  char result[MAX_LINES][MAX_CHARS_PER_LINE])
{
    qsort(result + start_line, end_line - start_line + 1, sizeof(result[0]),
          (ordering == 'a') ? cmp_string_incr : cmp_string_decr);
    list(list_type, special_character, start_line, end_line, result);
}

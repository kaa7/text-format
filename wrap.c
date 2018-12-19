#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "utils.h"

struct _Node {  // Linked list node
    char *str;
    struct _Node *next;
};

typedef struct _Node Node;

void wrap(int max_line_length, char result[MAX_LINES][MAX_CHARS_PER_LINE],
          int *result_line_count)
{
    int i, line = 0, original_line_count = *result_line_count;

    Node *start, *prev;
    for(i = 0; i < original_line_count; ++i) { // Make linked list of lines
        Node *node = malloc(sizeof(Node));
        node->str = malloc(sizeof(char) * MAX_CHARS_PER_LINE * 2);
        strcpy(node->str, result[i]);
        if(i == 0) {
            start = node;
            node->next = NULL;
        } else {
            prev->next = node;
        }
        prev = node;
    }
    prev->next = NULL;

    Node *nod = start;
    while(nod != NULL) {
        int len = strlen(nod->str);
        if(len != 0) {
            if(len > max_line_length) {
                int break_point = max_line_length;
                // Find break point
                while (!isspace(nod->str[break_point])) {
                    --break_point;
                }
                nod->str[break_point] = '\0';
                // Break current line and make a new one
                Node *new = malloc(sizeof(Node));
                new->str = malloc(sizeof(char) * MAX_CHARS_PER_LINE);
                strcpy(new->str, nod->str + break_point + 1);
                new->next = nod->next;
                nod->next = new;
            } else if(len < max_line_length && nod->next != NULL) {
                if(strlen(nod->next->str) != 0) { // If not end of paragraph
                    remove_trailing_whitespace(nod->str);
                    remove_starting_whitespace(&nod->next->str);
                    // Concatenate lines
                    strcat(nod->str, " ");
                    strcat(nod->str, nod->next->str);
                    // Remove next node
                    Node *temp = nod->next;
                    nod->next = temp->next;
                    free(temp);
                    continue;
                }
            }
        }
        nod = nod->next;
    }

    nod = start;
    line = 0;
    while(nod != NULL) {
        remove_trailing_whitespace(nod->str);
        strcpy(result[line++], nod->str);
        prev = nod;
        nod = nod->next;
        if(prev->str != NULL)
            free(prev->str);
        free(prev);
    }
    *result_line_count = line;
}

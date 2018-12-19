#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "syntax_checker.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    char buffer[MAX_CHARS_PER_LINE], // buffer used for reading line by line
         original[MAX_LINES][MAX_CHARS_PER_LINE],
         result[MAX_LINES][MAX_CHARS_PER_LINE];

    int original_line_count = 0,  // number of lines in the input file
        result_line_count = 0,    // number of lines in the output file
        i;

    if(argc != 4) {  // invalid number of arguments
        fprintf(stderr,
                "Usage: %s operations_string input_file output_file\n",
                argv[0]);
        return -1;
    }

    // Open input file for reading
    FILE *input_file = fopen(argv[2], "r");

    if(input_file == NULL) {
        fprintf(stderr, "File \"%s\" not found\n", argv[2]);
        return -2;
    }

    // Read data in file line by line
    while(fgets(buffer, 1000, input_file)) {
        buffer[strcspn(buffer, "\n")] = 0; // Strip newline from buffer
        strcpy(original[original_line_count], buffer);
        original_line_count++;
    }
    fclose(input_file);

    // Copy input to result
    for(i = 0; i < original_line_count; i++) {
        strcpy(result[i], original[i]);
    }
    result_line_count = original_line_count;

    // Read operations
    char op[10][20], *p;
    int op_count = 0;
    p = strtok(argv[1], DELIMITERS);
    while(p != NULL) {
        strcpy(op[op_count++], p);
        if(op_count >= MAX_NO_OPS) {
            printf("Too many operations! Only the first 10 will "
                   "be applied.\n");
            break;
        }
        p = strtok(NULL, DELIMITERS);
    }

    // Syntax check
    int error = 0;
    for(i = 0; i < op_count && !error; ++i) {
        error = syntax_check(op[i], get_max_word_length(original,
                             original_line_count));
        switch(error) {
        case -2:
            printf("Cannot wrap!\n");
            break;
        case -1:
            printf("Invalid operation!\n");
            break;
        }
    }
    // Apply operations if there aren't errors
    if(!error) {
        for(i = 0; i < result_line_count; ++i) {
            remove_trailing_whitespace(result[i]);
        }
        for(i = 0; i < op_count; ++i) {
            parse(op[i], result, &result_line_count);
        }

    }

    // Open output file for writing
    FILE *output_file = fopen(argv[3], "w");

    if(output_file == NULL) {
        fprintf(stderr, "Could not open or create file \"%s\"\n", argv[3]);
        return -2;
    }

    // Write result in output file
    for(i = 0; i < result_line_count; i++) {
        fputs(result[i], output_file);
        fputs("\n", output_file);
    }

    fclose(output_file);
    return 0;
}

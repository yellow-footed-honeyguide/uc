#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "conv_str_to_math_res.h"

int main(int argc, char *argv[]) {
    // Check if command-line arguments are provided
    if (argc > 1) {
        // Handle command-line arguments for power function...
    } else {
        char *exp;
        // Main calculator loop
        while (1) {
            // Prompt user for expression using readline
            exp = readline("Expression: ");
            if (exp == NULL) {
                break;
            }

            // Add the expression to the history
            add_history(exp);

            // Check if user wants to quit
            if (strcmp(exp, "q") == 0) {
                free(exp);
                break;
            }

            long double result = parseMathExpression(exp);
            char *formattedResult = formatResult(result);
            printf("Result: %s\n", formattedResult);

            free(exp);
        }
    }
    return 0;
}

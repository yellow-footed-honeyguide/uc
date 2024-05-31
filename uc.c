#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conv_str_to_math_res.h"

int main(int argc, char *argv[]) {
    // Check if command-line arguments are provided
    if (argc > 1) {
        // Handle command-line arguments for power function...
    } else {
        char exp[256];
        // Main calculator loop
        while (1) {
            // Prompt user for expression
            printf("Expression: ");
            fgets(exp, 256, stdin);
            exp[strcspn(exp, "\n")] = 0; // Remove newline character

            // Check if user wants to quit
            if (strcmp(exp, "q") == 0) {
                break;
            }
            long double result = parseMathExpression(exp);
            char *formattedResult = formatResult(result);
            printf("Result: %s\n", formattedResult);

        }
    }
    return 0;
}

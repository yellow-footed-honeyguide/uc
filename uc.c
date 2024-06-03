#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "handle_arguments.h"
#include "conv_str_to_math_res.h"
#include "exponent_mode.h"

int main(int argc, char *argv[]) {
    handle_arguments(argc, argv);

    char *exp;
    // If removed, there will be no var for the math expression from the user.

    while (1) {
    // If removed, the user will not be able to input multiple expressions.

        exp = readline("Expression: ");
        // If removed, the program will not prompt the user for input.

         if (exp == NULL) {
                break;
         }
         // If removed and the user enters EOF (Ctrl+D), the program will not exit the loop gracefully.

         add_history(exp);
         // If removed, the user will not be able to access previously entered expressions using the up/down arrow keys.

         switch (exp[0]) {
             case 'q':
                free(exp);
                exit(0);
             case 'e': {
                long double base, exponent;
                printf("Enter base: ");
                scanf("%Lf", &base);
                printf("Enter exponent: ");
                scanf("%Lf", &exponent);
                long double result = exponent_calc(base, exponent);
                printf("Result: %.0Lf\n", result);
                break;
             }
             default: {
                long double result = conv_str_to_math_res(exp);
                char *formatted_result = add_spaces_to_triples(result);
                printf("Result: %s\n", formatted_result);
                free(exp);
                break;
             }
         }
    }

    return 0;
}

    

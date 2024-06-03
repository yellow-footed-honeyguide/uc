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

    char *exp; // the math expression from the user.

    /* Loop gets multiple user input expressions. */
    while (1) {

        exp = readline("Expression: "); // prompt the user for input.

        /* Without this, entering EOF (Ctrl+D) won't exit 
           the loop gracefully. */
        if (exp == NULL) {
            break;
        }

         add_history(exp); // access prev  expressions using the up/down keys

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

    

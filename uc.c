#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "conv_str_to_math_res.h"
#include "handle_arguments.h"

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

         if (strcmp(exp, "q") == 0) {
             free(exp);
             break;
         }
         // If removed, the user will not be able to quit by entering 'q'.

         long double result = parseMathExpression(exp);
         // If removed, the user's expression will not be parsed and evaluated.

         char *formattedResult = formatResult(result);
         // If removed, the result will not be formatted as a string for display.
         printf("Result: %s\n", formattedResult);
         // If removed, the calculated result will not be displayed to the user.

         free(exp);
         // If removed, the memory allocated by readline for the exp var will not be freed, resulting in a memory leak.
    }

    return 0;
}

    

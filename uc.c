#include <stdio.h> // If removed, the program will not have access to standard input/output functions like printf.
#include <stdlib.h> // If removed, the program will not have access to memory allocation functions like malloc and free.
#include <string.h> // If removed, the program will not have access to string manipulation functions like strcmp.

#include <readline/readline.h>
#include <readline/history.h>
// If removed, the program will not have access to the readline library functions for enhanced user input and history management.

#include "conv_str_to_math_res.h" // If removed, the program will not have access to the functions defined in the conv_str_to_math_res.h header file.

int main(int argc, char *argv[]) {
    // If removed, the program will not have a valid entry point and will not compile.

    char *exp;
    // If removed, the exp variable will not be declared, and the program will not compile.

    while (1) {
    // If removed, the calculator will not run in a loop, and the user will not be able to input multiple expressions.

        exp = readline("Expression: ");
        // If removed, the program will not prompt the user for input and will not use the readline library for enhanced input handling.

         if (exp == NULL) {
                break;
         }
         // If removed and the user enters EOF (Ctrl+D), the program will not exit the loop gracefully.

         add_history(exp);
         // If removed, the user's input will not be added to the readline history, and the user will not be able to access previously entered expressions using the up/down arrow keys.

         if (strcmp(exp, "q") == 0) {
             free(exp);
             break;
         }
         // If removed, the user will not be able to quit the calculator by entering 'q'.

         long double result = parseMathExpression(exp);
         // If removed, the user's expression will not be parsed and evaluated.

         char *formattedResult = formatResult(result);
         // If removed, the result will not be formatted as a string for display.
         printf("Result: %s\n", formattedResult);
         // If removed, the calculated result will not be displayed to the user.

         free(exp);
         // If removed, the memory allocated by readline for the exp variable will not be freed, resulting in a memory leak.
    }

    return 0;
    // If removed, the program will have an undefined return value, which may cause issues in some environments.
}

    

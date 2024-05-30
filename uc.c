#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tinyexpr.h"
#include "number_formatter.h"

// Function to print an error message
void print_error() {
  printf("Error. Incorrect expression.\n");
}

int main(int argc, char *argv[]) {
  //char* number_formatter;

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

    // Remove spaces from the expression
    char *ptr = exp;
    while (*ptr) {
      if (*ptr == ' ') {
        memmove(ptr, ptr + 1, strlen(ptr));
      } else {
        ptr++;
        }
     }

            // Evaluate the expression using tinyexpr library
            int err;
            double result = te_interp(exp, &err);

            // Check for evaluation errors
            if (err != 0) {
                print_error();
            } else {
                // Check if result is an integer
                if (result == floor(result)) {
                    printf("%s\n", number_formatter(result));
                } else {
                    // Print with 10 decimal places
                    //printf("Result: %.10f\n\n", format_number_with_spaces(result)); 
                }
            }
        }
    }

    return 0;
}


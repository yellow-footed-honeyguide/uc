#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tinyexpr.h"

void print_error() {
    printf("Error. Incorrect expression.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // Handle command-line arguments for power function...
    } else {
        char exp[256];
        while (1) {
            printf("Expression: ");
            fgets(exp, 256, stdin);
            exp[strcspn(exp, "\n")] = 0; // Remove newline character

            if (strcmp(exp, "q") == 0) {
                break;
            }

            // Remove spaces
            char *ptr = exp;
            while (*ptr) {
                if (*ptr == ' ') {
                    memmove(ptr, ptr + 1, strlen(ptr));
                } else {
                    ptr++;
                }
            }

            int err;
            double result = te_interp(exp, &err);
            if (err != 0) {
                print_error();
            } else {
                printf("Result: %.2f\n\n", result);
            }
        }
    }
    return 0;
}
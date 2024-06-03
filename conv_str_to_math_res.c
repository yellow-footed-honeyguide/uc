#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


long double conv_str_to_math_res(const char *expr) {
    char buffer[1024] = {0}; // to avoid undefined behavior
    int bufferIndex = 0;     // current position in the buffer
    long double total = 0;   // final result
    long double current_numb = 0; // the numb. being parsed from the expression
    char lastOperator = '+';

    for (int i = 0; expr[i] != '\0'; i++) {
        /* The current character being processed, 
           which is necessary for checking its type 
           (digit, space, operator) and appending it to the buffer.
        */
        char c = expr[i];

        /* Grab digits and dots from expression and add to buffer. */
        if (isdigit(c) || c == '.') {
            buffer[bufferIndex++] = c;
        } else if (c == ' ') {
            continue; // skip whitespaces characters
        } else {
            buffer[bufferIndex] = '\0'; // end for correct work of strtold
            current_numb = strtold(buffer, NULL); // conv str to nubmer
            bufferIndex = 0; // reset to avoid next number add to previous

            /* Arithmetic operation on the last number. */
            if (lastOperator == '+') {
                total += current_numb;
            } else if (lastOperator == '-') {
                total -= current_numb;
            } else if (lastOperator == '*') {
                total *= current_numb;
            } else if (lastOperator == '/') {
                total /= current_numb;
            }

            lastOperator = c;
        }
    }

    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        current_numb = strtold(buffer, NULL);

        if (lastOperator == '+') {
            total += current_numb;
        } else if (lastOperator == '-') {
            total -= current_numb;
        } else if (lastOperator == '*') {
            total *= current_numb;
        } else if (lastOperator == '/') {
            total /= current_numb;
        }
    }

    return total;
}


char *add_spaces_to_triples(long double result) {
    static char formatted[1024];
    char temp[1024];

    /* Convert the result to a string with 4 decimal places, which is necessary for further formatting. */
    sprintf(temp, "%.4Lf", result);

    int len = strlen(temp); // len of str for locating the decimal point
    int decimalPoint = len; // position of the decimal point

    /* Find the position of the decimal point. */
    for (int i = 0; i < len; i++) {
        if (temp[i] == '.') {
            decimalPoint = i;
            break;
        }
    }

    int formattedIndex = 0; // track of the current position to append chars
    int count = 0; // store count the number of digits before the decimal point

    /* Insert the thousands separators in the formatted string. */
    for (int i = decimalPoint - 1; i >= 0; i--) {
        formatted[formattedIndex++] = temp[i];
        count++;
        if (count % 3 == 0 && i != 0) {
            formatted[formattedIndex++] = ' ';
        }
    }

    /*  Null-terminated for defined behavior when using it as a string. */
    formatted[formattedIndex] = '\0';

    int len_formatted = strlen(formatted);
    for (int i = 0; i < len_formatted / 2; i++) {
        char temp = formatted[i];
        formatted[i] = formatted[len_formatted - i - 1];
        formatted[len_formatted - i - 1] = temp;
    }

    /* Add decimal point to formatted result. */
    if (decimalPoint != len) {
        formatted[formattedIndex++] = '.';
        for (int i = decimalPoint + 1; i < len; i++) {
            formatted[formattedIndex++] = temp[i];
        }
        formatted[formattedIndex] = '\0';
    }
    return formatted;
}

/*
int main() {
    //char expression[] = "15+344.5 + 10 500 -8";
    char expression[] = "10000/3";
    long double result = conv_str_to_math_res(expression);
    char *formatted_result = add_spaces_to_triples(result);
    printf("Result: %s\n", formatted_result);
    return 0;
}
*/


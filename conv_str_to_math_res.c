#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long double conv_str_to_math_res(const char *expr) {
    char buffer[1024] = {0};       // to avoid undefined behavior
    int bufferIndex = 0;           // current position in the buffer
    long double total = 0;         // final result
    long double current_numb = 0;  // the numb. being parsed from the expression
    char last_operator = '+';

    for (int i = 0; expr[i] != '\0'; i++) {
        /* The current character being processed,
           which is necessary for checking its type
           (digit, space, operator) and appending it to the buffer. */
        char c = expr[i];

        /* Grab digits and dots from expression and add to buffer. */
        if (isdigit(c) || c == '.') {
            buffer[bufferIndex++] = c;
        } else if (c == ' ') {
            continue;  // skip whitespaces characters
        } else {
            buffer[bufferIndex] = '\0';            // end for correct work of strtold
            current_numb = strtold(buffer, NULL);  // conv str to nubmer
            bufferIndex = 0;                       // reset to avoid next number add to previous

            /* This block performs the arithmetic operation based on the
               last operator encountered. It is necessary to apply
               the correct operation to the running total and the
               current number. The if-else statements check the
               last_operator variable and perform the corresponding operation (addition,
               subtraction, multiplication, or division) between the total and current_numb. */
            if (last_operator == '+') {
                total += current_numb;
            } else if (last_operator == '-') {
                total -= current_numb;
            } else if (last_operator == '*') {
                total *= current_numb;
            } else if (last_operator == '/') {
                total /= current_numb;
            }

            last_operator = c;
        }
    }

    /* This block handles the case when there are remaining digits
       in the buffer after the loop ends. It is necessary to process
       the last number in the expression. Similar to previous block,
       it performs the arithmetic operation based on the last
       operator encountered, updating the total accordingly. */
    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        current_numb = strtold(buffer, NULL);

        if (last_operator == '+') {
            total += current_numb;
        } else if (last_operator == '-') {
            total -= current_numb;
        } else if (last_operator == '*') {
            total *= current_numb;
        } else if (last_operator == '/') {
            total /= current_numb;
        }
    }

    return total;
}

char *add_spaces_to_triples(long double result) {
    static char formatted[1024];
    char temp[1024];
    int is_integer = 1;  // Flag to check if the number is an integer

    // Convert the result to a string with 4 decimal places
    sprintf(temp, "%.4Lf", result);
    int len = strlen(temp);
    int decimalPoint = len;

    // Find the position of the decimal point and check if it's an integer
    for (int i = 0; i < len; i++) {
        if (temp[i] == '.') {
            decimalPoint = i;
            // Check if all digits after decimal point are zero
            for (int j = i + 1; j < len; j++) {
                if (temp[j] != '0') {
                    is_integer = 0;
                    break;
                }
            }
            break;
        }
    }

    int formattedIndex = 0;
    int count = 0;

    // Insert the thousands separators
    for (int i = decimalPoint - 1; i >= 0; i--) {
        formatted[formattedIndex++] = temp[i];
        count++;
        if (count % 3 == 0 && i != 0) {
            formatted[formattedIndex++] = ' ';
        }
    }

    formatted[formattedIndex] = '\0';

    // Reverse the integer part
    int len_formatted = strlen(formatted);
    for (int i = 0; i < len_formatted / 2; i++) {
        char temp = formatted[i];
        formatted[i] = formatted[len_formatted - i - 1];
        formatted[len_formatted - i - 1] = temp;
    }

    // Append the fractional part if it's not an integer
    if (!is_integer && decimalPoint != len) {
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

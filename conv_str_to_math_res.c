#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long double evaluateExpression(const char *expr);
char *formatResult(long double result);
void reverseString(char *str);

long double parseMathExpression(const char *expr) {
    long double result = evaluateExpression(expr);
    return result;
}

long double evaluateExpression(const char *expr) {
    char buffer[1024] = {0};
    int bufferIndex = 0;
    long double total = 0;
    long double currentNumber = 0;
    char lastOperator = '+';

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (isdigit(c) || c == '.') {
            buffer[bufferIndex++] = c;
        } else if (c == ' ') {
            continue;
        } else {
            buffer[bufferIndex] = '\0';
            currentNumber = strtold(buffer, NULL);
            bufferIndex = 0;

            if (lastOperator == '+') {
                total += currentNumber;
            } else if (lastOperator == '-') {
                total -= currentNumber;
            } else if (lastOperator == '*') {
                total *= currentNumber;
            } else if (lastOperator == '/') {
                total /= currentNumber;
            }

            lastOperator = c;
        }
    }

    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        currentNumber = strtold(buffer, NULL);

        if (lastOperator == '+') {
            total += currentNumber;
        } else if (lastOperator == '-') {
            total -= currentNumber;
        } else if (lastOperator == '*') {
            total *= currentNumber;
        } else if (lastOperator == '/') {
            total /= currentNumber;
        }
    }

    return total;
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char *formatResult(long double result) {
    static char formatted[1024];
    char temp[1024];
    sprintf(temp, "%.4Lf", result);

    int len = strlen(temp);
    int decimalPoint = len;
    for (int i = 0; i < len; i++) {
        if (temp[i] == '.') {
            decimalPoint = i;
            break;
        }
    }

    int formattedIndex = 0;
    int count = 0;
    for (int i = decimalPoint - 1; i >= 0; i--) {
        formatted[formattedIndex++] = temp[i];
        count++;
        if (count % 3 == 0 && i != 0) {
            formatted[formattedIndex++] = ' ';
        }
    }

    formatted[formattedIndex] = '\0';
    reverseString(formatted);

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
    long double result = parseMathExpression(expression);
    char *formattedResult = formatResult(result);
    printf("Result: %s\n", formattedResult);
    return 0;
}
*/

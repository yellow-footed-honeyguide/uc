#include <stdio.h>  // sprintf.
#include <stdlib.h> // strtold.
#include <string.h> // strlen and strcpy.
#include <ctype.h>  // isdigit.

long double evaluateExpression(const char *expr);
char *formatResult(long double result);
void reverseString(char *str);

long double parseMathExpression(const char *expr) {
    long double result = evaluateExpression(expr);
    return result;
}
// If removed, the program will not have the parseMathExpression function, which is used to parse and evaluate the user's input expression.

long double evaluateExpression(const char *expr) {
    char buffer[1024] = {0};
    // If removed, the buffer will not be initialized to zero, which may lead to undefined behavior when appending characters to it.

    int bufferIndex = 0;
    // If removed, the program will not have a variable to keep track of the current position in the buffer, which is necessary for appending characters and null-terminating the buffer.

    long double total = 0;
    // If removed, the program will not have a variable to store the running total of the evaluated expression, which is essential for the final result.

    long double currentNumber = 0;
    // If removed, the program will not have a variable to store the current number being parsed from the expression, which is necessary for performing the arithmetic operations.

    char lastOperator = '+';
    // If removed, the program will not have a variable to store the last encountered operator, which is necessary for determining the arithmetic operation to perform on the current number.

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        // If removed, the program will not have a variable to store the current character being processed, which is necessary for checking its type (digit, space, operator) and appending it to the buffer.
        
        if (isdigit(c) || c == '.') {
            buffer[bufferIndex++] = c;
        }
        // If removed, the program will not append digits and decimal points to the buffer, which is necessary for building the current number.
        
        else if (c == ' ') {
            continue;
        }
        // If removed, the program will not skip over whitespace characters, which may lead to incorrect parsing of the expression.
        
        else {
            buffer[bufferIndex] = '\0';
            // If removed, the buffer will not be null-terminated, which is necessary for converting it to a number using strtold.
            
            currentNumber = strtold(buffer, NULL);
            // If removed, the program will not convert the buffer to a number, which is necessary for performing the arithmetic operations.
            
            bufferIndex = 0;
            // If removed, the bufferIndex will not be reset to 0, which will cause the next number to be appended to the previous one, leading to incorrect parsing.
            
            lastOperator = c;
            // If removed, the lastOperator will not be updated with the current operator, which will cause the program to use the wrong operator for the next number.
        }
    }

   if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        // If removed, the buffer will not be null-terminated, which is necessary for converting it to a number using strtold.
        
        currentNumber = strtold(buffer, NULL);
        // If removed, the program will not convert the buffer to a number, which is necessary for performing the arithmetic operation on the last number.
        
        if (lastOperator == '+') {
            total += currentNumber;
        } else if (lastOperator == '-') {
            total -= currentNumber;
        } else if (lastOperator == '*') {
            total *= currentNumber;
        } else if (lastOperator == '/') {
            total /= currentNumber;
        }
        // If any of these conditions are removed, the program will not perform the corresponding arithmetic operation on the last number, leading to incorrect results.
    }
    
    return total;
    // If removed, the program will not return the final evaluated result, and the calling function will receive an undefined value.
}

void reverseString(char *str) {
    int len = strlen(str);
    // If removed, the program will not calculate the length of the string, which is necessary for reversing it.
    
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        // If any of these lines are removed, the program will not properly swap the characters to reverse the string.
    }
}
// If the entire reverseString function is removed, the program will not have the ability to reverse the formatted result string, which is necessary for displaying the result with the correct order of thousands separators.

char *formatResult(long double result) {
    static char formatted[1024];
    // If removed, the program will not have a buffer to store the formatted result string, and the function will not be able to return a valid string.
    
    char temp[1024];
    // If removed, the program will not have a temporary buffer to store the string representation of the result, which is necessary for further formatting.
    
    sprintf(temp, "%.4Lf", result);
    // If removed, the program will not convert the result to a string with 4 decimal places, which is necessary for further formatting.
    
    int len = strlen(temp);
    // If removed, the program will not calculate the length of the temporary string, which is necessary for locating the decimal point and formatting the thousands separators.
    
    int decimalPoint = len;
    // If removed, the program will not have a variable to store the position of the decimal point, which is necessary for formatting the thousands separators.
    
    for (int i = 0; i < len; i++) {
        if (temp[i] == '.') {
            decimalPoint = i;
            break;
        }
    }
    // If removed, the program will not find the position of the decimal point, which is necessary for formatting the thousands separators.
    
    int formattedIndex = 0;
    // If removed, the program will not have a variable to keep track of the current position in the formatted string, which is necessary for appending characters.
    
    int count = 0;
    // If removed, the program will not have a variable to count the number of digits before the decimal point, which is necessary for inserting the thousands separators.
    
    for (int i = decimalPoint - 1; i >= 0; i--) {
        formatted[formattedIndex++] = temp[i];
        count++;
        if (count % 3 == 0 && i != 0) {
            formatted[formattedIndex++] = ' ';
        }
        // If removed, the program will not insert the thousands separators in the formatted string.
    }
    
    formatted[formattedIndex] = '\0';
    // If removed, the formatted string will not be null-terminated, which may lead to undefined behavior when using it as a string.
    
    reverseString(formatted);
    // If removed, the formatted string will be in reverse order, with the thousands separators in the wrong positions.
    
    if (decimalPoint != len) {
        formatted[formattedIndex++] = '.';
        for (int i = decimalPoint + 1; i < len; i++) {
            formatted[formattedIndex++] = temp[i];
        }
        formatted[formattedIndex] = '\0';
        // If removed, the program will not append the decimal point and the digits after it to the formatted string, resulting in an incomplete formatted result.
    }
    
    return formatted;
    // If removed, the program will not return the formatted result string, and the calling function will receive an undefined value.
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

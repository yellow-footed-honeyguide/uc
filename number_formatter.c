#include <stdio.h>
#include <string.h>
#include <stdlib.h>           // For malloc
#include "number_formatter.h"

char* number_formatter(int num) {
    char num_str[50];
    char* formatted_str;
    int len, i, j, count;

    // Convert the number to a string
    sprintf(num_str, "%d", num);

    len = strlen(num_str);
    formatted_str = malloc(len + (len / 3) + 1); // Allocate memory for the formatted string
    if (formatted_str == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    j = 0;
    count = 0;

    // Loop through the string from the end to the beginning
    for (i = len - 1; i >= 0; i--) {
        formatted_str[j++] = num_str[i];
        count++;

        // Insert a space after every third digit
        if (count == 3 && i != 0) {
            formatted_str[j++] = ' ';
            count = 0;
        }
    }

    formatted_str[j] = '\0';

    // Reverse the string to get the correct order
    for (i = 0; i < j / 2; i++) {
        char temp = formatted_str[i];
        formatted_str[i] = formatted_str[j - i - 1];
        formatted_str[j - i - 1] = temp;
    }

    return formatted_str;
}

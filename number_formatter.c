#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For malloc

char* number_formatter(double num) {
    char num_str[50];
    char* formatted_str;
    int len, i, j, count;
    
    int integer_part = (int)num; // Get the integer part of the number
    double fractional_part = num - integer_part; // Get the fractional part of the number

    // Convert the integer part to a string
    sprintf(num_str, "%d", integer_part);

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

    // Handle the fractional part
    if (fractional_part > 0) {
        char fractional_str[20];
        sprintf(fractional_str, "%.2f", num); // Convert the original number to string with precision
        char* decimal_pos = strchr(fractional_str, '.'); // Find the position of the decimal point
        if (decimal_pos != NULL) {
            strcat(formatted_str, decimal_pos); // Concatenate the decimal part to the formatted string
        }
    }

    return formatted_str;
}

/*
int main(int argc, char *argv[]){
    double result = 10500444.5434;

    printf("%s\n", number_formatter(10500));
    printf("%s\n", number_formatter(result));
    return 0;
}
*/

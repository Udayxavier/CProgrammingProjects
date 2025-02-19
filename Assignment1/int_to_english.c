/*
 * Program Name: Integer to English Converter
 * Purpose: To convert a given integer (1-999) to its equivalent English word representation.
 * Author: Uday Tyagi (Student Number: 251372780)
 * Date: October 9, 2024
 */

#include <stdio.h>
#include <stdlib.h>

// Function to convert numbers 1-19 to words
const char* convert_1_to_19(int number) {
    const char* words[] = {
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    };
    return words[number - 1];
}

// Function to convert tens (20, 30, ..., 90) to words
const char* convert_tens(int number) {
    const char* words[] = {
        "twenty", "thirty", "forty", "fifty",
        "sixty", "seventy", "eighty", "ninety"
    };
    return words[number / 10 - 2];
}

// Function to convert any integer between 1 and 999 to English words
void convert_to_words(int number) {
    if (number == 0) {
        printf("zero");
        return;
    }

    if (number >= 100) {
        printf("%s hundred", convert_1_to_19(number / 100));
        number %= 100;
        if (number > 0) {
            printf(" and ");
        }
    }

    if (number >= 20) {
        printf("%s", convert_tens(number));
        number %= 10;
        if (number > 0) {
            printf("-%s", convert_1_to_19(number));
        }
    } else if (number > 0) {
        printf("%s", convert_1_to_19(number));
    }
}

int main() {
    int number;

    while (1) {
        // Prompt the user for input
        printf("\nPlease enter a value (1-999, 0 to quit): ");
        scanf("%d", &number);

        // Handle quit condition
        if (number == 0) {
            printf("Exiting the program.\n");
            break;
        }

        // Validate input range
        if (number < 1 || number > 999) {
            printf("Invalid input. Please enter a value between 1 and 999.\n");
        } else {
            // Display the English word representation
            printf("You entered the number ");
            convert_to_words(number);
            printf(".\n");
        }
    }

    return 0;
}


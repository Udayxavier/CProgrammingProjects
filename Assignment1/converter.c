/*
 * Program Name: Unit Converter
 * Purpose: To convert a given quantity from one measuring unit to another 
 *          based on user choice. Supports conversion between grams/ounces, 
 *          square meters/square yards, litres/pints, and meters/feet.
 * Author: Uday Tyagi (Student Number: 251372780)
 * Date: October 9, 2024
 */

#include <stdio.h>

int main() {
    int choice;            // Variable to store the user's choice for conversion type
    float value, result;   // Variables for input value and conversion result
    char direction;        // Variable to store the conversion direction

    while (1) {
        // Display the main menu for the user
        printf("\nUnit Conversion Menu:\n");
        printf("1. Grams to Ounces (and vice versa)\n");
        printf("2. Square Meters to Square Yards (and vice versa)\n");
        printf("3. Litres to Pints (and vice versa)\n");
        printf("4. Meters to Feet (and vice versa)\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the conversion based on the user's choice
        switch (choice) {
            case 1:
                // Grams and Ounces Conversion
                printf("Please enter a value in grams or ounces: ");
                scanf("%f", &value);
                // Prompt user for conversion direction
                printf("Enter 'G' for Grams to Ounces or 'O' for Ounces to Grams: ");
                scanf(" %c", &direction); // Space before %c to skip any whitespace
                if (direction == 'G' || direction == 'g') {
                    result = value * 0.03527; // Grams to Ounces conversion
                    printf("Your conversion is: %.2f grams is equal to %.2f ounces\n", value, result);
                } else if (direction == 'O' || direction == 'o') {
                    result = value / 0.03527; // Ounces to Grams conversion
                    printf("Your conversion is: %.2f ounces is equal to %.2f grams\n", value, result);
                } else {
                    printf("Invalid direction. Returning to the main menu.\n");
                }
                break;

            case 2:
                // Square Meters and Square Yards Conversion
                printf("Please enter a value in square meters or square yards: ");
                scanf("%f", &value);
                // Prompt user for conversion direction
                printf("Enter 'M' for Square Meters to Square Yards or 'Y' for Square Yards to Square Meters: ");
                scanf(" %c", &direction);
                if (direction == 'M' || direction == 'm') {
                    result = value * 1.19599; // Square Meters to Square Yards conversion
                    printf("Your conversion is: %.2f square meters is equal to %.2f square yards\n", value, result);
                } else if (direction == 'Y' || direction == 'y') {
                    result = value / 1.19599; // Square Yards to Square Meters conversion
                    printf("Your conversion is: %.2f square yards is equal to %.2f square meters\n", value, result);
                } else {
                    printf("Invalid direction. Returning to the main menu.\n");
                }
                break;

            case 3:
                // Litres and Pints Conversion
                printf("Please enter a value in litres or pints: ");
                scanf("%f", &value);
                // Prompt user for conversion direction
                printf("Enter 'L' for Litres to Pints or 'P' for Pints to Litres: ");
                scanf(" %c", &direction);
                if (direction == 'L' || direction == 'l') {
                    result = value * 2.11338; // Litres to Pints conversion
                    printf("Your conversion is: %.2f litres is equal to %.2f pints\n", value, result);
                } else if (direction == 'P' || direction == 'p') {
                    result = value / 2.11338; // Pints to Litres conversion
                    printf("Your conversion is: %.2f pints is equal to %.2f litres\n", value, result);
                } else {
                    printf("Invalid direction. Returning to the main menu.\n");
                }
                break;

            case 4:
                // Meters and Feet Conversion
                printf("Please enter a value in meters or feet: ");
                scanf("%f", &value);
                // Prompt user for conversion direction
                printf("Enter 'M' for Meters to Feet or 'F' for Feet to Meters: ");
                scanf(" %c", &direction);
                if (direction == 'M' || direction == 'm') {
                    result = value * 3.28084; // Meters to Feet conversion
                    printf("Your conversion is: %.2f meters is equal to %.2f feet\n", value, result);
                } else if (direction == 'F' || direction == 'f') {
                    result = value / 3.28084; // Feet to Meters conversion
                    printf("Your conversion is: %.2f feet is equal to %.2f meters\n", value, result);
                } else {
                    printf("Invalid direction. Returning to the main menu.\n");
                }
                break;

            case 5:
                // Exit the program
                printf("Quitting the program. Goodbye!\n");
                return 0;

            default:
                // Handle invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


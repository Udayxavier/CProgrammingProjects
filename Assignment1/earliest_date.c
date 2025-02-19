/*
 * Program Name: Earliest Date Finder
 * Purpose: To find the earliest date entered by the user in the format mm/dd/yy.
 * Author: Uday Tyagi (Student Number: 251372780)
 * Date: October 9, 2024
 */

#include <stdio.h>

// Function to check if the current date is earlier than the earliest date
int is_earlier(int month1, int day1, int year1, int month2, int day2, int year2) {
    if (year1 < year2) {
        return 1; // Current date is earlier
    } else if (year1 == year2) {
        if (month1 < month2) {
            return 1; // Current date is earlier
        } else if (month1 == month2) {
            if (day1 < day2) {
                return 1; // Current date is earlier
            }
        }
    }
    return 0; // Current date is not earlier
}

int main() {
    int month, day, year;
    int earliest_month = 0, earliest_day = 0, earliest_year = 0;
    int first_input = 1; // Flag to check if it's the first valid input

    while (1) {
        // Prompt user for input
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &day, &year);

        // Exit condition
        if (month == 0 && day == 0 && year == 0) {
            break;
        }

        // Check if this is the first valid date entered
        if (first_input) {
            earliest_month = month;
            earliest_day = day;
            earliest_year = year;
            first_input = 0; // Disable the flag after the first input
        } else {
            // Compare the current date with the earliest date
            if (is_earlier(month, day, year, earliest_month, earliest_day, earliest_year)) {
                earliest_month = month;
                earliest_day = day;
                earliest_year = year;
            }
        }
    }

    // Display the earliest date if at least one date was entered
    if (!first_input) {
        printf("%d/%d/%02d is the earliest date\n", earliest_month, earliest_day, earliest_year);
    } else {
        printf("No valid dates were entered.\n");
    }

    return 0;
}


#include "reminder.h"

// Define the global variable November here
struct Month November = {30, 6, {""}, {false}};

int main(void) {
    char reminder[MAX_STR_LEN];
    int day;

    // Main loop to keep asking the user for input until 0 is entered
    while (1) {
        day = read_reminder(reminder, MAX_STR_LEN);

        // Exit condition when user enters 0
        if (day == 0) {
            break;
        }

        // Insert the reminder into the calendar and print the updated calendar
        insert_to_calendar(day, reminder);
        print_calendar();
    }

    return 0;
}


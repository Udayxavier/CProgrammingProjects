#include "reminder.h"

// Function to insert a reminder into the calendar
void insert_to_calendar(int day, const char* value) {
    // Check if the day is within the valid range of the month
    if (day < 1 || day > November.month_days) {
        printf("Invalid day. Please enter a valid day between 1 and %d.\n", November.month_days);
        return;
    }

    // Insert the reminder and set the reminder flag for the specified day
    strncpy(November.reminder_str[day - 1], value, MAX_STR_LEN - 1);
    November.reminder_str[day - 1][MAX_STR_LEN - 1] = '\0'; // Ensure null-termination
    November.reminders[day - 1] = true; // Mark the day as having a reminder
}

// Function to read a reminder from the user
int read_reminder(char *str, int n) {
    int day;

    // Prompt the user for input
    printf("Enter day and reminder (0 to quit): ");
    scanf("%d", &day);
    getchar(); // Consume the newline character left by scanf

    // If the user entered 0, return it to signal quitting
    if (day == 0) {
        return day;
    }

    // Read the reminder string and remove the newline character
    fgets(str, n, stdin);
    str[strcspn(str, "\n")] = '\0'; // Ensure the newline is removed
    return day;
}

// Function to print the calendar and list of reminders
void print_calendar() {
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int start = November.start_day;
    int days = November.month_days;
    int day_counter = 1;

    // Print initial spaces for the starting day of the week
    for (int i = 0; i < start; i++) {
        printf("     ");
    }

    // Print the days of the month, marking those with reminders
    for (int i = start; i < 7; i++) {
        if (November.reminders[day_counter - 1]) {
            printf("(%2d) ", day_counter);
        } else {
            printf(" %2d  ", day_counter);
        }
        day_counter++;
    }
    printf("\n");

    // Print the rest of the days in the month
    while (day_counter <= days) {
        for (int i = 0; i < 7 && day_counter <= days; i++) {
            if (November.reminders[day_counter - 1]) {
                printf("(%2d) ", day_counter);
            } else {
                printf(" %2d  ", day_counter);
            }
            day_counter++;
        }
        printf("\n");
    }

    // Print the list of reminders
    printf("\nReminders:\n");
    for (int i = 0; i < days; i++) {
        if (November.reminders[i]) {
            printf("Day %2d: %s\n", i + 1, November.reminder_str[i]);
        }
    }
}


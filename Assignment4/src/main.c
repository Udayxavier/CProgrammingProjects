#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "interact.h"
#include "reminder.h"
#include "linked_list.h"

#define FILENAME "reminders.txt"

// Global variable for the current month
Month currentMonth;

// Signal handler function to save reminders and exit gracefully
void signalHandler(int signal) {
    printf("\nSignal caught: ");
    switch (signal) {
        case SIGINT:
            printf("SIGINT (Interrupt)\n");
            break;
        case SIGTERM:
            printf("SIGTERM (Termination)\n");
            break;
        case SIGSEGV:
            printf("SIGSEGV (Segmentation Fault)\n");
            break;
        default:
            printf("Unknown signal\n");
            break;
    }

    // Save reminders to the file before exiting
    writingToFile(&currentMonth, FILENAME);
    printf("Reminders saved successfully before exiting due to signal.\n");
    exit(EXIT_SUCCESS);
}

// Function to set up signal handling
void setupSignalHandlers() {
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    signal(SIGSEGV, signalHandler);
}

int main() {
    // Initialize the Month structure
    initializeMonth(&currentMonth);

    // Load reminders from the file
    readingFromFile(&currentMonth, FILENAME);

    // Print the initialized calendar with reminders
    printf("Initialized Calendar:\n");
    printCalendar(&currentMonth);

    // Set up signal handling
    setupSignalHandlers();

    // User interaction loop to add reminders
    while (1) {
        readReminder(&currentMonth);
        printf("\nCurrent Calendar with Reminders:\n");
        printCalendar(&currentMonth);

        printf("\nDo you want to add more reminders? (Enter 0 to stop, 1 to continue): ");
        int choice;
        scanf("%d", &choice);
        flushBuffer(); // Clear any leftover input

        if (choice == 0) {
            break; // Exit the loop if the user enters 0
        }
    }

    // Save reminders to the file before exiting
    writingToFile(&currentMonth, FILENAME);

    // Free all allocated memory for reminders
    for (int i = 0; i < currentMonth.month_days; i++) {
        freeAll(currentMonth.reminders[i]);
        currentMonth.reminders[i] = NULL;
    }

    printf("Reminders saved successfully.\n");
    return 0;
}


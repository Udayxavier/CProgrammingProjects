#include "interact.h"

// Function to read a reminder from the user and add it to the month
void readReminder(Month *month) {
    int day;
    char reminderText[256];

    printf("Enter day and reminder (0 to quit): ");
    scanf("%d", &day);
    flushBuffer(); // Clear any extra input

    if (day == 0) {
        return; // Exit the function if the user enters 0
    }

    printf("Enter reminder: ");
    fgets(reminderText, sizeof(reminderText), stdin);
    reminderText[strcspn(reminderText, "\n")] = '\0'; // Remove the newline character

    addReminder(month, day, reminderText);
}

// Function to read reminders from a file and load them into the month structure
void readingFromFile(Month *month, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No reminders file found. Starting fresh.\n");
        return;
    }

    int day;
    char reminderText[256];
    while (fscanf(file, "%d %[^\n]", &day, reminderText) != EOF) {
        addReminder(month, day, reminderText);
    }

    fclose(file);
}

// Function to write reminders to a file before exiting
void writingToFile(const Month *month, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < month->month_days; i++) {
        Node *current = month->reminders[i];
        while (current != NULL) {
            fprintf(file, "%d %s\n", i + 1, current->reminder);
            current = current->next;
        }
    }

    fclose(file);
}

// Function to flush the input buffer
void flushBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard the characters until newline or EOF
    }
}


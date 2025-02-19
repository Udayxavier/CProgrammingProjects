#include "interact.h"

// Function to read reminders from a file and load them into the month structure
void readingFromFile(Month *month, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No reminders file found. Starting fresh.\n");
        return;
    }

    int day;
    char reminderText[256];
    int remindersLoaded = 0;
    while (fscanf(file, "%d %[^\n]", &day, reminderText) != EOF) {
        addReminder(month, day, reminderText);
        remindersLoaded++;
    }

    fclose(file);
    if (remindersLoaded > 0) {
        printf("Loaded %d reminders from %s.\n", remindersLoaded, filename);
    }
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
    printf("Reminders saved to %s.\n", filename);
}


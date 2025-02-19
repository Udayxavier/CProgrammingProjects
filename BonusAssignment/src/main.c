#include "reminder.h"
#include "interact.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "reminders.txt"

Month currentMonth;

void printUsage() {
    printf("Usage:\n");
    printf("  gcal add <day> <reminder>      - Add a reminder\n");
    printf("  gcal remove <day> <index>      - Remove a reminder\n");
    printf("  gcal view                      - View calendar and all reminders\n");
    printf("  gcal today                     - View today's reminders\n");
}

int main(int argc, char *argv[]) {
    initializeMonth(&currentMonth);
    readingFromFile(&currentMonth, FILENAME);

    if (argc < 2) {
        printUsage();
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc < 4) {
            printf("Error: Missing day or reminder.\n");
            printUsage();
            return 1;
        }
        int day = atoi(argv[2]);
        char reminder[256];
        snprintf(reminder, sizeof(reminder), "%s", argv[3]);
        for (int i = 4; i < argc; i++) {
            strncat(reminder, " ", sizeof(reminder) - strlen(reminder) - 1);
            strncat(reminder, argv[i], sizeof(reminder) - strlen(reminder) - 1);
        }
        addReminder(&currentMonth, day, reminder);
    } else if (strcmp(argv[1], "remove") == 0) {
        if (argc != 4) {
            printf("Error: Missing day or index.\n");
            printUsage();
            return 1;
        }
        int day = atoi(argv[2]);
        int index = atoi(argv[3]);
        removeReminder(&currentMonth, day, index);
    } else if (strcmp(argv[1], "view") == 0) {
        printCalendar(&currentMonth);
    } else if (strcmp(argv[1], "today") == 0) {
        printTodayReminders(&currentMonth);
    } else {
        printf("Error: Unknown command '%s'.\n", argv[1]);
        printUsage();
        return 1;
    }

    writingToFile(&currentMonth, FILENAME);
    for (int i = 0; i < currentMonth.month_days; i++) {
        freeAll(currentMonth.reminders[i]);
    }
    return 0;
}


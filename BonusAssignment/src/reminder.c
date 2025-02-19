#include "reminder.h"
#include <time.h>

// Function to initialize the month
void initializeMonth(Month *month) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    month->month_idx = t->tm_mon;
    t->tm_mday = 1;
    mktime(t);
    month->start_day = t->tm_wday;

    month->month_days = t->tm_mday;
    while (t->tm_mon == month->month_idx) {
        month->month_days = t->tm_mday;
        t->tm_mday++;
        mktime(t);
    }

    for (int i = 0; i < 31; i++) {
        month->reminders[i] = NULL;
    }
}

// Function to add a reminder
void addReminder(Month *month, int day, const char *reminderText) {
    if (day < 1 || day > month->month_days) {
        printf("Invalid day: Must be between 1 and %d.\n", month->month_days);
        return;
    }
    month->reminders[day - 1] = addNode(month->reminders[day - 1], reminderText);
}

// Function to remove a reminder
void removeReminder(Month *month, int day, int index) {
    if (day < 1 || day > month->month_days) {
        printf("Invalid day: Must be between 1 and %d.\n", month->month_days);
        return;
    }
    deleteNodeByIndex(&month->reminders[day - 1], index);
}

// Function to print the calendar
void printCalendar(const Month *month) {
    printf("Calendar for month %d\n", month->month_idx + 1);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < month->start_day; i++) {
        printf("    ");
    }

    for (int day = 1; day <= month->month_days; day++) {
        printf("%3d ", day);
        if ((day + month->start_day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");

    for (int i = 0; i < month->month_days; i++) {
        if (month->reminders[i] != NULL) {
            printf("Day %d reminders:\n", i + 1);
            printList(month->reminders[i]);
        }
    }
}

// Function to print reminders for today
void printTodayReminders(Month *month) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printRemindersForDay(month, t->tm_mday);
}

// Function to print reminders for a specific day
void printRemindersForDay(const Month *month, int day) {
    if (day < 1 || day > month->month_days) {
        printf("Invalid day: Must be between 1 and %d.\n", month->month_days);
        return;
    }
    if (month->reminders[day - 1] != NULL) {
        printList(month->reminders[day - 1]);
    } else {
        printf("No reminders for day %d.\n", day);
    }
}


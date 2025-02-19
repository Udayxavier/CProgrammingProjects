#ifndef REMINDER_H
#define REMINDER_H

#include "linked_list.h"

// Struct for storing month details and reminders
typedef struct {
    int month_idx;           // Index of the current month (0-11)
    int start_day;           // Start day of the month (0 = Sunday, 1 = Monday, ...)
    int month_days;          // Total number of days in the month
    Node *reminders[31];     // Array of linked lists to store reminders for each day
} Month;

// Function declarations
void initializeMonth(Month *month);
void addReminder(Month *month, int day, const char *reminderText);
void printCalendar(const Month *month);
void printRemindersForDay(const Month *month, int day);

#endif // REMINDER_H


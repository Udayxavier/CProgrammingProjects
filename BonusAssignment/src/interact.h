#ifndef INTERACT_H
#define INTERACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reminder.h"

// Function declarations
void readingFromFile(Month *month, const char *filename); // Load reminders from a file
void writingToFile(const Month *month, const char *filename); // Save reminders to a file

#endif // INTERACT_H


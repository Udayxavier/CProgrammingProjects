#ifndef INTERACT_H
#define INTERACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reminder.h"

// Function declarations
void readReminder(Month *month);
void readingFromFile(Month *month, const char *filename);
void writingToFile(const Month *month, const char *filename);
void flushBuffer(void);

#endif // INTERACT_H


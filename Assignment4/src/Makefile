# Compiler and flags
CC = gcc
CFLAGS = -g -Wall

# Executable name
EXEC = reminder_program

# Source files and object files
SRCS = main.c interact.c reminder.c linked_list.c
OBJS = $(SRCS:.c=.o)

# Default target to build the executable
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the project directory, including reminders.txt
clean:
	rm -f $(OBJS) $(EXEC) reminders.txt

# Rule to clean only object files
clean_objs:
	rm -f $(OBJS)

# Phony targets (not actual files)
.PHONY: all clean clean_objs


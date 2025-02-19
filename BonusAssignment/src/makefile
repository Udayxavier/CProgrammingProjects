# Compiler and flags
CC = gcc
CFLAGS = -g -Wall

# Executable name
EXEC = gcal

# Source and object files
SRCS = main.c interact.c reminder.c linked_list.c
OBJS = $(SRCS:.c=.o)

# Installation directory (default to local user bin)
INSTALL_DIR = $(HOME)/.local/bin

# Default target: build the executable
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Rule to clean only object files
clean_objs:
	rm -f $(OBJS)

# Rule to install the program
install: $(EXEC)
	@echo "Installing $(EXEC) to $(INSTALL_DIR)..."
	mkdir -p $(INSTALL_DIR)
	cp $(EXEC) $(INSTALL_DIR)
	@echo "Installation complete. Make sure $(INSTALL_DIR) is in your PATH."

# Rule to uninstall the program
uninstall:
	@echo "Uninstalling $(EXEC) from $(INSTALL_DIR)..."
	rm -f $(INSTALL_DIR)/$(EXEC)
	@echo "Uninstallation complete."

# Phony targets (not real files)
.PHONY: all clean clean_objs install uninstall


#!/bin/bash

# Define variables
SRC_DIR="./src"
INSTALL_DIR="$HOME/.local/bin"
EXECUTABLE="gcal"

# Step 1: Navigate to the source directory and build the program
echo "Building the program in $SRC_DIR..."
cd "$SRC_DIR" || { echo "Error: Source directory $SRC_DIR does not exist."; exit 1; }
make
if [ $? -ne 0 ]; then
    echo "Error: Failed to build the program."
    exit 1
fi
echo "Build completed successfully."
cd - || exit # Return to the original directory

# Step 2: Create the installation directory if it doesn't exist
if [ ! -d "$INSTALL_DIR" ]; then
    echo "Creating installation directory at $INSTALL_DIR..."
    mkdir -p "$INSTALL_DIR"
    if [ $? -ne 0 ]; then
        echo "Error: Failed to create installation directory."
        exit 1
    fi
else
    echo "Installation directory already exists."
fi

# Step 3: Copy the executable to the installation directory
echo "Copying $EXECUTABLE to $INSTALL_DIR..."
cp "$SRC_DIR/$EXECUTABLE" "$INSTALL_DIR/"
if [ $? -ne 0 ]; then
    echo "Error: Failed to copy the executable."
    exit 1
fi
echo "Executable copied successfully."

# Step 4: Update the PATH in ~/.bashrc
if ! grep -q "$INSTALL_DIR" "$HOME/.bashrc"; then
    echo "Updating PATH in ~/.bashrc..."
    echo "export PATH=\$PATH:$INSTALL_DIR" >> "$HOME/.bashrc"
    echo "PATH updated successfully. Please run 'source ~/.bashrc' to apply changes."
else
    echo "PATH already includes $INSTALL_DIR. No changes made."
fi

echo "Installation complete. You can now use the 'gcal' command globally."


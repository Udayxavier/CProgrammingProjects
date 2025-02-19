#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void get_user_input(int *array, int n, int m);
void fill_random_numbers(int *array, int start, int end);
void print_array(int *array, int size, const char *message);
void copy_array(int *source, int *destination, int size);
void bubble_sort(int *array, int size);
void quick_sort(int *array, int low, int high);
int partition(int *array, int low, int high);
void sort_and_measure(int *array, int *sorted_array, int size, int algorithm);
void handle_menu(int *numbers, int *sorted_numbers, int n, int m);

// Main function
int main() {
    int n, m;
    int choice;
    srand(time(NULL));  // Seed for random number generation

    // Main loop for handling the program
    do {
        printf("Enter the number of numbers you will input (n): ");
        scanf("%d", &n);
        printf("Enter the array length (m): ");
        scanf("%d", &m);

        // Validate n and m conditions
        if (n <= m && n % 2 == 0 && m % 2 == 0) {
            int numbers[2][m];
            get_user_input(numbers[0], n, m);  // Get user input and fill the rest with random numbers
            int sorted_array[m];
            copy_array(numbers[0], sorted_array, m);

            handle_menu(numbers[0], sorted_array, n, m);  // Main menu for sorting options and other commands
        } else {
            printf("Error: Ensure that m >= n and both m and n are even numbers.\n");
        }
    } while (1);

    return 0;
}

// Function to handle main menu and commands
void handle_menu(int *numbers, int *sorted_numbers, int n, int m) {
    char command;
    int algorithm_choice;
    
    do {
        printf("\nChoose sorting algorithm: (0) Quick sort, (1) Bubble sort\n");
        printf("Enter choice (0 or 1): ");
        scanf("%d", &algorithm_choice);

        if (algorithm_choice == 0 || algorithm_choice == 1) {
            sort_and_measure(numbers, sorted_numbers, m, algorithm_choice);
        } else {
            printf("Invalid choice. Please enter 0 or 1.\n");
        }

        printf("\nChoose a command:\n(R) Re-generate random numbers and choose a different algorithm\n");
        printf("(N) Enter new values for n and m\n(S) Use a different algorithm on the same array\n(Q) Quit\n");
        printf("Enter command: ");
        getchar();  // Clear the newline from buffer
        scanf("%c", &command);

        switch (command) {
            case 'R':
                fill_random_numbers(numbers, n, m);
                printf("Random numbers re-generated.\n");
                break;
            case 'N':
                return;  // Exit the menu to enter new values
            case 'S':
                // Keep the same array, prompt for sorting again
                printf("Using different algorithm on the same array.\n");
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid command. Try again.\n");
        }
    } while (command != 'Q');
}

// Function to get user input and fill rest of the array with random numbers if needed
void get_user_input(int *array, int n, int m) {
    printf("Enter %d numbers:\n", n);
    int i;
    for (i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Error in input. Generating random values instead.\n");
            break;
        }
    }
    fill_random_numbers(array, i, m);  // Fill remaining spaces with random numbers
}

// Function to fill array with random numbers from a given start index
void fill_random_numbers(int *array, int start, int end) {
    for (int i = start; i < end; i++) {
        array[i] = rand() % 10001;  // Random numbers up to 10000
    }
}

// Function to print array with a message
void print_array(int *array, int size, const char *message) {
    printf("%s\n", message);
    for (int i = 0; i < size; i++) {
        printf("%6d ", array[i]);
    }
    printf("\n");
}

// Function to copy elements from source array to destination array
void copy_array(int *source, int *destination, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

// Bubble sort implementation
void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Quick sort implementation
void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

// Partition function for quick sort
int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

// Function to sort the array using chosen algorithm and measure the time taken
void sort_and_measure(int *array, int *sorted_array, int size, int algorithm) {
    copy_array(array, sorted_array, size);  // Copy to sorted_array to maintain original array
    time_t time1 = time(NULL);  // Start time

    if (algorithm == 0) {
        quick_sort(sorted_array, 0, size - 1);
    } else if (algorithm == 1) {
        bubble_sort(sorted_array, size);
    }

    time_t time2 = time(NULL);  // End time
    double duration = difftime(time2, time1);  // Calculate duration in seconds

    print_array(array, size, "Original Array:");
    print_array(sorted_array, size, "Sorted Array:");
    printf("Sorting Duration: %.0f seconds\n", duration);
}


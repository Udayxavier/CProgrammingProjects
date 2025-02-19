#include "linked_list.h"

// Function to add a new node to the head of the linked list
Node *addNode(Node *head, const char *reminderText) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->reminder, reminderText, sizeof(newNode->reminder) - 1);
    newNode->reminder[sizeof(newNode->reminder) - 1] = '\0'; // Ensure null-termination
    newNode->next = head; // Insert at the head of the list
    return newNode;
}

// Function to delete a node by index
void deleteNodeByIndex(Node **head, int index) {
    if (*head == NULL || index < 1) {
        printf("Invalid index: No reminder found.\n");
        return;
    }

    Node *current = *head;
    Node *prev = NULL;

    int count = 1;
    while (current != NULL && count < index) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid index: No reminder found at index %d.\n", index);
        return;
    }

    if (prev == NULL) {
        *head = current->next; // Remove the head node
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Reminder %d removed successfully.\n", index);
}

// Function to free all nodes in the linked list
void freeAll(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to print all reminders in the linked list
void printList(const Node *head) {
    int count = 1;
    while (head != NULL) {
        printf("(%d) %s\n", count++, head->reminder);
        head = head->next;
    }
}


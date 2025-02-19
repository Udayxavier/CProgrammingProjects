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

// Function to delete a specific reminder node from the linked list
void deleteNode(Node **head, const char *reminderText) {
    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->reminder, reminderText) == 0) {
            if (prev == NULL) {
                *head = current->next; // The node to delete is the head
            } else {
                prev->next = current->next; // Bypass the current node
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Reminder not found.\n");
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


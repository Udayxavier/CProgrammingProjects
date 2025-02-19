#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct Node {
    char reminder[256];
    struct Node *next;
} Node;

// Function declarations for linked list operations
Node *addNode(Node *head, const char *reminderText);
void deleteNode(Node **head, const char *reminderText);
void freeAll(Node *head);
void printList(const Node *head);

#endif // LINKED_LIST_H


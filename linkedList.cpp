#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;  // Correctly defining pointer to the next node
};

struct Node* head = NULL;  // Head pointer initialized to NULL

// Function to insert a node at the beginning
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for new node
    if (newNode == NULL) {
        printf("Memory overflow\n");
        return;
    }
    newNode->data = value;  // Assign the data to the new node
    newNode->next = head;   // Point new node to the current head
    head = newNode;         // Update head to the new node
    printf("%d inserted into the list\n", value);
}

// Function to delete a specific node by value
void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;  // Pointers to traverse the list
    if (temp != NULL && temp->data == value) {  // If the head node itself holds the value
        head = temp->next;  // Move head to the next node
        free(temp);         // Free the old head
        printf("%d deleted from the list\n", value);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present in the list
    if (temp == NULL) {
        printf("%d not found\n", value);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);  // Free the memory
    printf("%d deleted from the list\n", value);
}

// Function to display the linked list
void displayList() {
    struct Node* temp = head;  // Start from the head
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // Print each node's data
        temp = temp->next;             // Move to the next node
    }
    printf("NULL\n");  // Indicate the end of the list
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    deleteNode(20);
    displayList();
    return 0;
}

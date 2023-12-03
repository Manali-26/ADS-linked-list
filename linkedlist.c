#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Take values from the user and insert at the beginning
    int value;
    printf("Enter values to insert into the linked list (enter -1 to stop):\n");
    while (1) {
        printf("Enter a value: ");
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        insertAtBeginning(&head, value);
    }

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Note: In a real-world scenario, you should free allocated memory.

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;

        printf("Inserted %d as the head node.\n", value);
        return;
    }

    struct Node* temp = *head;

    // Traverse until the last node
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;

    printf("Inserted %d at the end.\n", value);
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is currently empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

// Function to delete a node by its value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("The list is currently empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node holds the key
    if (temp->data == key) {

        // If there is only one node
        if (temp->next == *head) {
            *head = NULL;
            free(temp);

            printf("Element %d deleted successfully.\n", key);
            return;
        }

        // Find the last node
        struct Node* last = *head;

        while (last->next != *head) {
            last = last->next;
        }

        // Update the last node's link
        *head = temp->next;
        last->next = *head;

        free(temp);

        printf("Element %d deleted successfully.\n", key);
        return;
    }

    // Search for the node to be deleted
    prev = temp;
    temp = temp->next;

    while (temp != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == *head) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);

    printf("Element %d deleted successfully.\n", key);
}

// Main function with menu-driven interface
int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\n--- Circular Linked List Operations Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Delete Node by Value\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 4:
                printf("Exiting program. Freeing memory...\n");

                // Free all remaining nodes
                if (head != NULL) {
                    struct Node* current = head->next;

                    while (current != head) {
                        struct Node* temp = current;
                        current = current->next;
                        free(temp);
                    }

                    free(head);
                    head = NULL;
                }

                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

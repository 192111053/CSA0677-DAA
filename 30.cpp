#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a number at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Function to insert a number at the middle of the list
struct Node* insertAtMiddle(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        int count = 1;

        while (temp->next != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (count == position - 1) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Invalid position!\n");
            free(newNode);
        }
    }

    return head;
}

// Function to insert a number at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the list
void freeList(struct Node* head) {
    struct Node* temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

// Example usage
int main() {
    struct Node* head = NULL;

    // Insert at the beginning
    head = insertAtBeginning(head, 5);
    displayList(head);

    // Insert in the middle (position 2)
    head = insertAtMiddle(head, 10, 2);
    displayList(head);

    // Insert at the end
    head = insertAtEnd(head, 15);
    displayList(head);

    // Insert at an invalid position (position 4)
    head = insertAtMiddle(head, 20, 4);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}

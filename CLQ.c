#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Initialize front and rear pointers to NULL
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the circular queue is empty
int isEmpty() {
    return front == NULL && rear == NULL;
}

// Function to enqueue an element into the circular queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front; // Make the circular connection
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Make the circular connection
    }
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty, cannot dequeue\n");
        return;
    }

    int removedValue = front->data;
    struct Node* temp = front;

    if (front == rear) {
        // If there is only one element in the queue
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Update the circular connection
    }

    free(temp);
    printf("Dequeued: %d\n", removedValue);
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = front;
    printf("Circular Queue: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != front);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


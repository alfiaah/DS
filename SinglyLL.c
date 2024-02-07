#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to display the linked list in reverse order
void displayReverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    int count = 0;
    int dataArr[100]; // Assuming a maximum of 100 nodes
	int i;
    // Traverse the list and store data in an array
    while (current != NULL) {
        dataArr[count++] = current->data;
        current = current->next;
    }

    // Display the data in reverse order
    for (i = count - 1; i >= 0; i--) {
        printf("%d -> ", dataArr[i]);
    }
    printf("NULL\n");
}

int main() {
    int n,i,data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }

    printf("Linked List in Reverse Order: ");
    displayReverse();

    return 0;
}


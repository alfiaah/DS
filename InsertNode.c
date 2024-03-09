#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

node* head = NULL;

// Function to create a new node
node* createNode(int e) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = e;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(int e) {
    node* newNode = createNode(e);
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(int e) {
    node* newNode = createNode(e);
    if (head == NULL) {
        head = newNode;
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a new node after a specified element in the list
void insertAfterElement(int key, int e) {
    node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            node* newNode = createNode(e);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Element not found in the list.\n");
}

// Function to display the list
void display() {
    node* current = head;
    if (current == NULL) {
        printf("List is Empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n\n");
}

int menu() {
    int ch;
    printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert after Element\n4.Display\n5.Exit\nYour Choice: ");
    scanf("%d", &ch);
    return ch;
}

void process(int ch) {
    int e, key;
    for (ch = menu(); ch != 5; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted at the beginning: ");
                scanf("%d", &e);
                insertAtBeginning(e);
                break;
            case 2:
                printf("Enter the element to be inserted at the end: ");
                scanf("%d", &e);
                insertAtEnd(e);
                break;
            case 3:
                printf("Enter the element to be inserted after: ");
                scanf("%d", &key);
                printf("Enter the new element: ");
                scanf("%d", &e);
                insertAfterElement(key, e);
                break;
            case 4:
                display();
                break;
            default:
                printf("Error: Invalid Choice\n");
                break;
        }
    }
}

int main() {
    int ch;
    process(ch);
    return 0;
}


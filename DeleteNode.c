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

// Function to insert a new node
void insert(int e) {
    node* newNode = createNode(e);
    newNode->next = head;
    head = newNode;
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    node* temp = head;
    head = head->next;
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Function to delete a node with specified data element
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->data == key) {
        node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        if (current->next->data == key) {
            node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", key);
}

// Function to display the list
void display() {
    node* current = head;
    if (current == NULL) {
        printf("List is empty\n");
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
    printf("\n1.Insert\n2.Delete from Beginning\n3.Delete from End\n4.Delete by Value\n5.Display\n6.Exit\nYour Choice: ");
    scanf("%d", &ch);
    return ch;
}

void process(int ch) {
    int key, e;
    for (ch = menu(); ch != 6; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &e);
                insert(e);
                break;
            case 2:
                deleteFromBeginning();
                break;
            case 3:
                deleteFromEnd();
                break;
            case 4:
                printf("Enter the element to be deleted: ");
                scanf("%d", &key);
                deleteNode(key);
                break;
            case 5:
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


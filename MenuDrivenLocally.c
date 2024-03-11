#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE]; // Global array
int size = 0;     // Current size of the array

void displayArray(int arr[], int size) {
	int i;
    printf("Array elements: ");
    for ( i= 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int size, int element) {
    if (size < MAX_SIZE) {
        arr[size] = element;
        size++;
    } else {
        printf("Array is full. Cannot insert more elements.\n");
    }
    return size;
}

int searchElement(int arr[], int size, int element) {
	int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

int deleteElement(int arr[], int size, int element) {
	int i;
    int index = searchElement(arr, size, element);
    if (index != -1) {
        for (i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        printf("Element %d deleted successfully.\n", element);
    } else {
        printf("Element not found. Cannot delete.\n");
    }
    return size;
}

void sortArray(int arr[], int size) {
    int temp,i,j;
    for (i = 0; i < size; i++) {
        for ( j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, result;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Delete Element\n");
        printf("4. Sort Array\n");
        printf("5. Display Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                size = insertElement(arr, size, element);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                result = searchElement(arr, size, element);
                if (result != -1) {
                    printf("Element %d found at index %d.\n", element, result);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                size = deleteElement(arr, size, element);
                break;
            case 4:
                sortArray(arr, size);
                break;
            case 5:
                displayArray(arr, size);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}


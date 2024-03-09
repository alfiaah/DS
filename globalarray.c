#include <stdio.h>

int arr[10], n, pos = -1, i, j, ch, k, flag = 0;

void insert() {
    if (pos >= 9) {
        printf("Array is full\n");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &arr[++pos]);
    }
}

void search() {
    printf("Enter the element to be searched: ");
    scanf("%d", &k);
    for (i = 0; i <= pos; i++) {
        if (k == arr[i]) {
            printf("Element found at position %d\n", i);
            flag = 1;
            break;
        }
    }
    if (flag != 1) {
        printf("Element not found\n");
    }
}

void delete() {
    printf("Enter the element to be deleted: ");
    scanf("%d", &k);
    for (i = 0; i <= pos; i++) {
        if (k == arr[i]) {
            arr[i] = -1; // Mark the element as deleted
            printf("Element deleted\n");
            flag = 1;
            break;
        }
    }
    if (flag != 1) {
        printf("Element not found\n");
    }
}

void sort() {
    int temp;
    for (i = 0; i <= pos; i++) {
        for (j = i + 1; j <= pos; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array sorted in non-increasing order\n");
}

void display() {
    printf("Array Elements are: ");
    for (i = 0; i <= pos; i++) {
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int menu() {
    printf("\n1. Insert\n2. Search\n3. Delete\n4. Sort\n5. Display\n6. Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void process() {
    for (ch = menu(); ch != 6; ch = menu()) {
        flag = 0; // Reset the flag
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                delete();
                break;
            case 4:
                sort();
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
}

int main() {
    printf("Enter the size of the array (up to 10): ");
    scanf("%d", &n);
    if (n > 10) {
        printf("Array size should be at most 10.\n");
        return 1; // Exit with an error code
    }

    pos = n - 1; // Set the initial position to the last index of the array
    process();
    return 0;
}


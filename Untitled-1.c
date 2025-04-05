// Implementation of Insertion and deletion in a specific                   23/01/25
// position in an Array using Function.
#include <stdio.h>
#define MAX_SIZE 100
void displayArray(int arr[], int size);
void insertElement(int arr[], int *size, int position, int element);
void deleteElement(int arr[], int *size, int position);
int main() {
    int arr[MAX_SIZE];
    int size = 0, choice, element, position;
    printf("Array Operations: Insertion and Deletion at Specific Positions\n");
    do {
        printf("\nMenu:\n");
        printf("1. Insert element at a specific position\n");
        printf("2. Delete element from a specific position\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (size >= MAX_SIZE) {
                    printf("Array is full. Cannot insert more elements.\n");
                    break;
                }
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (0 to %d): ", size);
                scanf("%d", &position);
                if (position < 0 || position > size) {
                    printf("Invalid position! Valid range is 0 to %d.\n", size);
                } else {
                    insertElement(arr, &size, position, element);
                    printf("Element inserted successfully.\n");
                }
                break;
            case 2:
                if (size <= 0) {
                    printf("Array is empty. Cannot delete elements.\n");
                    break;
                }
            printf("Enter the position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                if (position < 0 || position >= size) {
                    printf("Invalid position! Valid range is 0 to %d.\n", size - 1);
                } else {
                    deleteElement(arr, &size, position);
                    printf("Element deleted successfully.\n");
                }
                break;
            case 3:
                if (size <= 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    displayArray(arr, size);
                }
                break;
           case 4:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }printf("\n");}
void insertElement(int arr[], int *size, int position, int element) {
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}
void deleteElement(int arr[], int *size, int position) {
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

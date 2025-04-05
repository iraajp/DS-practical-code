// Implement Singly linked list                                      30/01/25
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data);
void insertNode(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void displayList(struct Node* head);
void freeList(struct Node** head);
int main() {
    struct Node* head = NULL;
    int choice, data, key;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
                case 2:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
                case 3:
                displayList(head);
                break;
                case 4:
                freeList(&head);
                return 0;
                default:
                printf("Invalid choice!\n");}}}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted\n");
}void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");
}
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void freeList(struct Node** head) {
    struct Node *current = *head, *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

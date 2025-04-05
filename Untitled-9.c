// Implementation of reversing list using a stack                      20/03/25
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;
typedef struct Stack {
    StackNode* top;
} Stack;
ListNode* createListNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
StackNode* createStackNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}
void push(Stack* stack, int data) {
StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}
void appendToList(ListNode** head, int data) {
    ListNode* newNode = createListNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    ListNode* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
}
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
ListNode* reverseList(ListNode* head) {
    // If list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Stack* stack = createStack();
        ListNode* current = head;
    while (current != NULL) {
        push(stack, current->data);
        current = current->next;}
    ListNode* reversedHead = NULL;
    while (!isEmpty(stack)) {
        appendToList(&reversedHead, pop(stack));
    }    free(stack);
    return reversedHead;
}
void freeList(ListNode* head) {
    ListNode* current = head;
    ListNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;}}
int main() {
    ListNode* head = NULL;
    appendToList(&head, 1);
    appendToList(&head, 2);
    appendToList(&head, 3);
    appendToList(&head, 4);
    appendToList(&head, 5);
    printf("Original List: ");
    printList(head);
    ListNode* reversedHead = reverseList(head);
    printf("Reversed List: ");
    printList(reversedHead);
    freeList(head);
    freeList(reversedHead);
    return 0;
}

// Array Implementation of Stack.                                            06/02/25
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
void initializeStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void displayStack(Stack *s);
int main() {
    Stack stack;
    initializeStack(&stack);
    int choice, value;
    printf("Stack Implementation using Array\n");
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push element onto stack\n");
        printf("2. Pop element from stack\n");
        printf("3. Peek (View top element)\n");
        printf("4. Display stack elements\n");
        printf("5. Check if stack is empty\n");
        printf("6. Check if stack is full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                if (!isEmpty(&stack)) {
                    value = pop(&stack);
                    printf("Popped element: %d\n", value);
                } else {
                    printf("Stack Underflow! Cannot pop from an empty stack.\n");
                }
                break;
           case 3:
                if (!isEmpty(&stack)) {
                    value = peek(&stack);
                    printf("Top element: %d\n", value);
                } else {
                    printf("Stack is empty. No top element to display.\n");
                }break;
           case 4:
                displayStack(&stack);
                break;
           case 5:
                if (isEmpty(&stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }break;
            case 6:
                if (isFull(&stack)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
           case 7:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}
void initializeStack(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    
    int value = s->items[s->top];
    s->top--;
    return value;
}
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No element to peek.\n");
        return -1;
    }return s->items[s->top];
}
void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No elements to display.\n");
        return;
    }
     printf("Stack elements (from top to bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}










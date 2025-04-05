// Array implementation of linear Queues                                     20/02/25
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;
void initializeQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);
void displayQueue(Queue *q);
int main() {
    Queue queue;
    initializeQueue(&queue);
    int choice, value;
    printf("Linear Queue Implementation using Array\n");
    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue (Insert) element\n");
        printf("2. Dequeue (Remove) element\n");
        printf("3. Peek (View front element)\n");
        printf("4. Display queue elements\n");
        printf("5. Check if queue is empty\n");
        printf("6. Check if queue is full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
             case 2:
                if (!isEmpty(&queue)) {
                    value = dequeue(&queue);
                    printf("Dequeued element: %d\n", value);
                } else {
                printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
                }break;
                case 3:
                if (!isEmpty(&queue)) {
                    value = peek(&queue);
                    printf("Front element: %d\n", value);
                } else {
                    printf("Queue is empty. No front element to display.\n");
                }break;
            case 4:
                displayQueue(&queue);
                break;
            case 5:
                if (isEmpty(&queue)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }break;
            case 6:
                if (isFull(&queue)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }break;
            case 7:
                printf("Exiting the program.\n");
                break;
           default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q) {
    return q->front == -1;
}
int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue more elements.\n");
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d into the queue.\n", value);
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        initializeQueue(q); 
    } else {
        q->front++;
    }return value;}
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    }
    return q->items[q->front];
}
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No elements to display.\n");
        return;
    }
    printf("Queue elements (from front to rear):\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

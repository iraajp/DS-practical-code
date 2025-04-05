// Array implementation of circular Queue                                   27/02/25
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int itemCount;
} CircularQueue;
void initializeQueue(CircularQueue *q);
int isEmpty(CircularQueue *q);
int isFull(CircularQueue *q);
void enqueue(CircularQueue *q, int value);
int dequeue(CircularQueue *q);
int peek(CircularQueue *q);
void displayQueue(CircularQueue *q);
int main() {
    CircularQueue queue;
    initializeQueue(&queue);
    int choice, value;
    printf("Circular Queue Implementation using Array\n");
    printf("(Max size set to %d for demonstration purposes)\n", MAX_SIZE);
    do {
        printf("\nCircular Queue Operations Menu:\n");
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
                } break;
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
}void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->itemCount = 0;
}
int isEmpty(CircularQueue *q) {
    return q->itemCount == 0;
}
int isFull(CircularQueue *q) {
    return q->itemCount == MAX_SIZE;
}
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue more elements.\n");
        return;
    }
    
if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    q->itemCount++;
    printf("Enqueued %d into the queue.\n", value);
    printf("Front: %d, Rear: %d\n", q->front, q->rear);
}
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        initializeQueue(q);
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
        q->itemCount--;
    }
    
    return value;
}
int peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    }return q->items[q->front];
}
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No elements to display.\n");
        return;
    }
    printf("Queue elements (from front to rear):\n");
    int count = 0;
    int i = q->front;
    while (count < q->itemCount) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    printf("\n");
    printf("Front: %d, Rear: %d, Count: %d\n", q->front, q->rear, q->itemCount);
}

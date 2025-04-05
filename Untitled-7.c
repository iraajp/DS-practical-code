// Implementation of double ended linked list         			06/03/25
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    return deque;
}
int isEmpty(Deque* deque) {
    return (deque->size == 0);
}
void insertFront(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    deque->size++;
    printf("%d inserted at front\n", data);
}
void insertRear(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    deque->size++;
    printf("%d inserted at rear\n", data);
}
int deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }Node* temp = deque->front;
    int data = temp->data;
    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }
    free(temp);
    deque->size--;
    return data;
}
int deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    Node* temp = deque->rear;
    int data = temp->data;
    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }
    free(temp);
    deque->size--;
    return data;}
int getFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }return deque->front->data;
}
int getRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }return deque->rear->data;}
void display(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    Node* current = deque->front;
    printf("Deque elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}void destroyDeque(Deque* deque) {
    Node* current = deque->front;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }free(deque);
}
int main() {
    Deque* deque = createDeque();
    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    insertRear(deque, 30);
    display(deque);
    printf("Front element: %d\n", getFront(deque));
    printf("Rear element: %d\n", getRear(deque));
    printf("Deleted from front: %d\n", deleteFront(deque));
    printf("Deleted from rear: %d\n", deleteRear(deque));
 display(deque);
    destroyDeque(deque);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node * next;
};

struct LinkedQueue {
    struct Node *front;
    struct Node *rear;
};

bool isEmpty(struct LinkedQueue *queue) {
    return (queue->front == NULL);
}

bool enqueue(struct LinkedQueue *queue, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return false;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return true;
}

int dequeue(struct LinkedQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node *temp = queue->front;
    int value = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

void display (struct LinkedQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct LinkedQueue queue;
    queue.front = NULL;
    queue.rear = NULL;

    dequeue(&queue);

    enqueue(&queue, 10);
    display(&queue);
    enqueue(&queue, 20);
    display(&queue);
    enqueue(&queue, 30);
    display(&queue);

    dequeue(&queue);
    display(&queue);
    dequeue(&queue);
    display(&queue);
    dequeue(&queue);
    display(&queue);
}
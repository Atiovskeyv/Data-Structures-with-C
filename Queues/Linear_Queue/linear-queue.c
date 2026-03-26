#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int *array;
    int front;
    int rear;
    unsigned int capacity;
};

bool isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

bool isFull(struct Queue *queue) {
    return (queue->rear == (queue->capacity - 1));
}

bool enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return false;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    else {
        queue->rear++;
    }

    queue->array[queue->rear] = value;
    return true;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int temp = queue->array[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front++;
    }
    return temp;
}

void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Empty Queue\n");
        return;
    }
    for (int i = queue->front ; i <= queue->rear ; i++) {
        printf("%d ",queue->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    q.capacity = 5;
    q.array = malloc(q.capacity * sizeof(int));

    enqueue(&q,10);
    display(&q);
    enqueue(&q,20);
    display(&q);
    enqueue(&q,30);
    display(&q);

    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    free(q.array);
}
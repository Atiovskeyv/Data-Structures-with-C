#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CircularQueue {
        int *array;
        int front;
        int rear;
        unsigned int capacity;
};

bool isEmpty(struct CircularQueue *queue) {
        return (queue->front == -1);
}

bool isFull(struct CircularQueue *queue) {
        return(queue->front == (queue->rear + 1 )%queue->capacity);
}

bool enqueue(struct CircularQueue *queue, int value) {
        if (isFull(queue)) {
                printf("Queue is full\n");
                return false;
        }

        if (isEmpty(queue)) {
                queue->front = 0;
                queue->rear = 0;
        }

        else {
                queue->rear = (queue->rear + 1) % queue->capacity;
        }

        queue->array[queue->rear] = value;
        return true;
}

int dequeue(struct CircularQueue *queue) {
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
                queue->front = (queue->front + 1) % queue->capacity;
        }
        return temp;
}

void display(struct CircularQueue *queue) {
        if (isEmpty(queue)) {
                printf("Empty Queue\n");
                return;
        }

        int i = queue->front;

        while (1) {
                printf("%d ", queue->array[i]);

                if (i == queue->rear)
                        break;

                i = (i + 1) % queue->capacity;
        }
        printf("\n");
}

int main() {
        struct CircularQueue queue;
        queue.capacity = 5;
        queue.array = malloc(queue.capacity * sizeof(int));
        queue.array = malloc(queue.capacity * sizeof(int));
        if (queue.array == NULL) {
                printf("Memory allocation failed\n");
                return 1;
        }
        queue.front = -1;
        queue.rear = -1;

        enqueue(&queue, 10);
        display(&queue);
        enqueue(&queue, 20);
        display(&queue);
        enqueue(&queue, 30);
        display(&queue);
        enqueue(&queue, 40);
        display(&queue);
        enqueue(&queue, 50);
        display(&queue);
        enqueue(&queue, 60);

        dequeue(&queue);
        display(&queue);
        enqueue(&queue, 60);
        display(&queue);
        enqueue(&queue, 70);
        dequeue(&queue);
        display(&queue);
        dequeue(&queue);
        display(&queue);
        enqueue(&queue, 70);
        display(&queue);
        free(queue.array);
        return 0;
}
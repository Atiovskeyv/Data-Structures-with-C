#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ShiftQueue {
    int rear;
    unsigned int capacity;
    int *array;
};

bool isEmpty(struct ShiftQueue *queue) {
    return (queue->rear == -1);
}

bool isFull(struct ShiftQueue*queue) {
    return (queue->rear == queue->capacity - 1);
}

bool enqueue(struct ShiftQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full \n");
        return false;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
    return true;
}

int dequeue(struct ShiftQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty \n");
        return -1;
    }
    int temp = queue->array[0];
    for (int i = 0 ; i < queue->rear ; i++) {
        queue->array[i] = queue->array[i + 1];
    }
    queue->rear--;
    return temp;
}

void display(struct ShiftQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty \n");
        return;
    }
    for (int i = 0 ; i <= queue->rear ; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}
int main() {
    struct ShiftQueue queue;
    queue.capacity = 5;
    queue.rear = -1;
    queue.array = malloc(sizeof(int) * queue.capacity);

    dequeue(&queue);
    display(&queue);
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

    free(queue.array);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int top;
    unsigned int capacity;
    int *array;
};

bool isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

bool isFull(struct Stack *stack) {
    return (stack->top == stack->capacity-1);
}

int push(struct Stack *stack,int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return 1;
    }
    stack->top++;
    stack->array[stack->top] =value;
    return 0;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top];
}

int main(){
    struct Stack stack;
    stack.top = -1;
    stack.capacity = 3;
    stack.array = malloc(stack.capacity * sizeof(int));

    peek(&stack);
    pop(&stack);
    push(&stack,10);
    printf("%d\n",peek(&stack));
    push(&stack,20);
    printf("%d\n",peek(&stack));
    push(&stack,30);
    printf("%d\n",peek(&stack));
    pop(&stack);
    printf("%d\n",peek(&stack));
    push(&stack,30);
    push(&stack,40);

    free(stack.array);
    return 0;
}
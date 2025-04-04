#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int top;
    int arr[MAX];
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

struct Queue {
    struct Stack stack1, stack2;
};

void initQueue(struct Queue *queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

void enqueue(struct Queue *queue, int value) {
    push(&queue->stack1, value);
    printf("Enqueued: %d\n", value);
}

int dequeue(struct Queue *queue) {
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2)) {
        printf("Queue is empty\n");
        return -1;
    }

    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    return pop(&queue->stack2);
}

void printQueue(struct Queue *queue) {
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = queue->stack2.top; i >= 0; i--)
        printf("%d ", queue->stack2.arr[i]);

    for (int i = 0; i <= queue->stack1.top; i++)
        printf("%d ", queue->stack1.arr[i]);

    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printQueue(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printQueue(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    printQueue(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printQueue(&queue);

    return 0;
}


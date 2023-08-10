#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}
int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    } else if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
int main() {
    Queue q;
    initialize(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}

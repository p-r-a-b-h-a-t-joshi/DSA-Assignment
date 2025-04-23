#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} CQueue;

void initialize(CQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool isEmpty(CQueue *queue) {
    return queue->front == NULL;
}

void enQueue(CQueue *queue, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        newNode->next = newNode; 
        queue->front = queue->rear = newNode;
    } else {
        newNode->next = queue->front;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued successfully.\n", value);
}

void deQueue(CQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    Node *temp = queue->front;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front; 
    }

    printf("%d dequeued successfully.\n", temp->data);
    free(temp);
}

void display(CQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    Node *current = queue->front;
    printf("Queue elements: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front); 
    printf("\n");
}

int main() {
    CQueue queue;
    initialize(&queue);

    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enQueue(&queue, value);
                break;
            case 2:
                deQueue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

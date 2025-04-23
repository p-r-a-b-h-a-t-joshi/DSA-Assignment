#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *ptr;
} Node;

void printList(Node *);
Node *createList(int, Node *);
Node *insertAtBeginning(int, Node *);
Node *insertAtEnd(int, Node *);
Node *insertAnywhere(int, int, Node *);
Node *deleteEle(int, Node *);
Node *deleteAtStart(Node *);
Node *deleteAtEnd(Node *);

int main() 
{
    Node *head = NULL;
    int choice, n, data, pos;

    while (1) 
    {
        printf("\nEnter your choice:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Print the circular linked list\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert at specific position\n");
        printf("6. Delete a node\n");
        printf("7. Delete from beginning\n");
        printf("8. Delete from end\n");
        printf("9. Exit\n");
        
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                head = createList(n, head);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                head = insertAtBeginning(data, head);
                break;
            case 4:
                printf("Enter the data: ");
                scanf("%d", &data);
                head = insertAtEnd(data, head);
                break;
            case 5:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = insertAnywhere(data, pos, head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteEle(pos, head);
                break;
            case 7:
                head = deleteAtStart(head);
                break;
            case 8:
                head = deleteAtEnd(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

Node *createList(int n, Node *head)
{
    Node *temp, *newNode;
    if (n <= 0) return head;

    head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->ptr = head;
    temp = head;

    for (int i = 2; i <= n; i++) {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = i;
        newNode->ptr = head;
        temp->ptr = newNode;
        temp = newNode;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d -> ", temp->data);
        temp = temp->ptr;
    } while (temp != head);
    printf("HEAD\n");
}

Node *insertAtBeginning(int data, Node *head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    newNode->data = data;

    if (head == NULL) {
        newNode->ptr = newNode;
        return newNode;
    }

    while (temp->ptr != head) temp = temp->ptr;

    temp->ptr = newNode;
    newNode->ptr = head;
    return newNode;
}

Node *insertAtEnd(int data, Node *head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    newNode->data = data;

    if (head == NULL) {
        newNode->ptr = newNode;
        return newNode;
    }

    while (temp->ptr != head) temp = temp->ptr;

    temp->ptr = newNode;
    newNode->ptr = head;
    return head;
}

Node *insertAnywhere(int data, int pos, Node *head)
{
    if (pos <= 0) return insertAtBeginning(data, head);

    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    newNode->data = data;

    for (int i = 0; temp->ptr != head && i < pos - 1; i++) {
        temp = temp->ptr;
    }

    if (temp->ptr == head && pos > 0) {
        printf("Position out of range.\n");
        free(newNode);
        return head;
    }

    newNode->ptr = temp->ptr;
    temp->ptr = newNode;
    return head;
}

Node *deleteEle(int pos, Node *head)
{
    if (head == NULL || pos < 0) return head;

    if (pos == 0) return deleteAtStart(head);

    Node *temp = head, *prev = NULL;

    for (int i = 0; temp->ptr != head && i < pos; i++) {
        prev = temp;
        temp = temp->ptr;
    }

    if (temp->ptr == head && pos > 0) {
        printf("Position out of range.\n");
        return head;
    }

    prev->ptr = temp->ptr;
    free(temp);
    return head;
}

Node *deleteAtStart(Node *head)
{
    if (head == NULL) return NULL;

    Node *temp = head, *last = head;

    while (last->ptr != head) last = last->ptr;

    if (head->ptr == head) {
        free(head);
        return NULL;
    }

    last->ptr = head->ptr;
    head = head->ptr;
    free(temp);
    return head;
}

Node *deleteAtEnd(Node *head)
{
    if (head == NULL || head->ptr == head) {
        free(head);
        return NULL;
    }

    Node *temp = head, *prev = NULL;

    while (temp->ptr != head) {
        prev = temp;
        temp = temp->ptr;
    }

    prev->ptr = head;
    free(temp);
    return head;
}
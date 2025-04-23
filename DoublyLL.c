#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next, *prev;
} NODE;

NODE *head = NULL;


NODE *create(int n);
NODE *insertbeg(int data);
NODE *insertend(int data);
NODE *insertany(int data, int pos);
NODE *delbeg();
NODE *delend();
NODE *delany(int pos);
NODE *search(int key);
void print();
void revprint();

void main() {
    int choice, n, data, pos, key;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Create the doubly linked list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at specific position\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete specific node\n");
        printf("8. Search for an element\n");
        printf("9. Print the list\n");
        printf("10. Print the list in reverse\n");
        printf("11. Exit\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                head = create(n);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                head = insertbeg(data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                head = insertend(data);
                break;
            case 4:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = insertany(data, pos);
                break;
            case 5:
                head = delbeg();
                break;
            case 6:
                head = delend();
                break;
            case 7:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                head = delany(pos);
                break;
            case 8:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                NODE *found = search(key);
                if (found != NULL) {
                    printf("Element %d found.\n", found->data);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 9:
                print();
                break;
            case 10:
                revprint();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

NODE *create(int n) {
    if (n <= 0) return NULL;

    NODE *newNode, *temp;
    head = (NODE *)malloc(sizeof(NODE));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    head->prev = NULL;
    temp = head;

    for (int i = 2; i <= n; i++) {
        newNode = (NODE *)malloc(sizeof(NODE));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

NODE *insertbeg(int data) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) head->prev = newNode;

    head = newNode;
    return head;
}

NODE *insertend(int data) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    NODE *temp = head;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

NODE *insertany(int data, int pos) {
    if (pos <= 0) return insertbeg(data);

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    NODE *temp = head;
    newNode->data = data;

    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

NODE *delbeg() {
    if (head == NULL) return NULL;

    NODE *temp = head;
    head = head->next;

    if (head != NULL) head->prev = NULL;

    free(temp);
    return head;
}

NODE *delend() {
    if (head == NULL) return NULL;

    NODE *temp = head;

    while (temp->next != NULL) temp = temp->next;

    if (temp->prev != NULL) temp->prev->next = NULL;
    else head = NULL;

    free(temp);
    return head;
}

NODE *delany(int pos) {
    if (head == NULL || pos < 0) return head;

    if (pos == 0) return delbeg();

    NODE *temp = head;

    for (int i = 0; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;

    free(temp);
    return head;
}

NODE *search(int key) {
    NODE *temp = head;

    while (temp != NULL) {
        if (temp->data == key) return temp;
        temp = temp->next;
    }

    return NULL;
}

void print() {
    NODE *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void revprint() {
    NODE *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL) temp = temp->next;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
     
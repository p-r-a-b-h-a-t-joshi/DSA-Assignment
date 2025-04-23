#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct Node {
    int data;
    struct Node *LChild;
    struct Node *RChild;
} Node;

Node *root = NULL;

bool checkRoot() {
    return root != NULL;
}

void init(int val) {
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        root->data = val;
        root->LChild = NULL;
        root->RChild = NULL;
    } else {
        printf("Root already present!\n");
    }
}

Node* create(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->LChild = NULL;
    p->RChild = NULL;
    return p;
}

Node* setLChild(int val, Node *parent) {
    if (parent == NULL) {
        printf("Parent node is NULL!\n");
        return NULL;
    }
    Node *child = create(val);
    parent->LChild = child;
    return child;
}

Node* setRChild(int val, Node *parent) {
    if (parent == NULL) {
        printf("Parent node is NULL!\n");
        return NULL;
    }
    Node *child = create(val);
    parent->RChild = child;
    return child;
}

void inorderTraversal(Node *node) {
    if (node != NULL) {
        inorderTraversal(node->LChild);
        printf("%d ", node->data);
        inorderTraversal(node->RChild);
    }
}

void preorderTraversal(Node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorderTraversal(node->LChild);
        preorderTraversal(node->RChild);
    }
}

void postorderTraversal(Node *node) {
    if (node != NULL) {
        postorderTraversal(node->LChild);
        postorderTraversal(node->RChild);
        printf("%d ", node->data);
    }
}

void displayMenu() {
    printf("Binary Tree Operations:\n");
    printf("1. Initialize Root Node\n");
    printf("2. Add Left Child\n");
    printf("3. Add Right Child\n");
    printf("4. Inorder Traversal\n");
    printf("5. Preorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Exit\n");
}

int main() {
    int choice, val, parentVal;
    Node *parent;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for root node: ");
                scanf("%d", &val);
                init(val);
                break;

            case 2:
                printf("Enter value for left child: ");
                scanf("%d", &val);
                printf("Enter parent node value: ");
                scanf("%d", &parentVal);
                
                parent = root; 
                if (parent != NULL && parent->data == parentVal) {
                    setLChild(val, parent);
                } else {
                    printf("Parent node not found!\n");
                }
                break;

            case 3:
                printf("Enter value for right child: ");
                scanf("%d", &val);
                printf("Enter parent node value: ");
                scanf("%d", &parentVal);
                
                parent = root; 
                if (parent != NULL && parent->data == parentVal) {
                    setRChild(val, parent);
                } else {
                    printf("Parent node not found!\n");
                }
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

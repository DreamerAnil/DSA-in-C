#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* findMin(struct Node* node) {
    if (node == NULL) {
        return NULL;
    } else if (node->left == NULL) {
        return node;
    } else {
        return findMin(node->left);
    }
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    printf("1. Insert\n");
      printf("2. Delete\n");
        printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inorder traversal after insertion: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Inorder traversal after deletion: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
/*1. Insert
2. Delete
3. Exit
Enter your choice: 1
Enter the value to insert: 5
Inorder traversal after insertion: 5

Enter your choice: 1
Enter the value to insert: 6
Inorder traversal after insertion: 5 6

Enter your choice: 1
Enter the value to insert: 9
Inorder traversal after insertion: 5 6 9

Enter your choice: 1
Enter the value to insert: 0
Inorder traversal after insertion: 0 5 6 9

Enter your choice: 1
Enter the value to insert: 3
Inorder traversal after insertion: 0 3 5 6 9

Enter your choice: 2
Enter the value to delete: 6
Inorder traversal after deletion: 0 3 5 9*/



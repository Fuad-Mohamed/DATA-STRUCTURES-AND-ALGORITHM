#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count the number of nodes in a binary tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to display a binary tree using inorder traversal
void displayTree(struct Node* root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

// The required function to compare three binary trees
void compareBinaryTree(struct Node *A, struct Node *B, struct Node *C) {
    int countA = countNodes(A);
    int countB = countNodes(B);
    int countC = countNodes(C);

    printf("Number of nodes in Tree A: %d\n", countA);
    printf("Number of nodes in Tree B: %d\n", countB);
    printf("Number of nodes in Tree C: %d\n", countC);

    if (countA >= countB && countA >= countC) {
        printf("Tree A has the highest number of nodes (%d nodes).\n", countA);
        printf("Tree A elements (inorder): ");
        displayTree(A);
        printf("\n");
    } else if (countB >= countA && countB >= countC) {
        printf("Tree B has the highest number of nodes (%d nodes).\n", countB);
        printf("Tree B elements (inorder): ");
        displayTree(B);
        printf("\n");
    } else {
        printf("Tree C has the highest number of nodes (%d nodes).\n", countC);
        printf("Tree C elements (inorder): ");
        displayTree(C);
        printf("\n");
    }
}

// Function to free memory allocated for the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Test case creation function
void runTestCase(int testNum, struct Node* A, struct Node* B, struct Node* C) {
    printf("\n===== Test Case %d =====\n", testNum);
    compareBinaryTree(A, B, C);
}

int main() {
    // Test Case 1: Three different sized trees
    printf("Creating Test Case 1: Three trees with different number of nodes\n");

    // Tree A with 7 nodes
    struct Node* treeA1 = createNode(1);
    treeA1->left = createNode(2);
    treeA1->right = createNode(3);
    treeA1->left->left = createNode(4);
    treeA1->left->right = createNode(5);
    treeA1->right->left = createNode(6);
    treeA1->right->right = createNode(7);

    // Tree B with 3 nodes
    struct Node* treeB1 = createNode(10);
    treeB1->left = createNode(20);
    treeB1->right = createNode(30);

    // Tree C with 5 nodes
    struct Node* treeC1 = createNode(100);
    treeC1->left = createNode(200);
    treeC1->right = createNode(300);
    treeC1->left->left = createNode(400);
    treeC1->left->right = createNode(500);

    runTestCase(1, treeA1, treeB1, treeC1);

    // Test Case 2: Trees with same number of nodes
    printf("\nCreating Test Case 2: Two trees with equal highest number of nodes\n");

    // Tree A with 3 nodes
    struct Node* treeA2 = createNode(5);
    treeA2->left = createNode(3);
    treeA2->right = createNode(7);

    // Tree B with 5 nodes
    struct Node* treeB2 = createNode(10);
    treeB2->left = createNode(5);
    treeB2->right = createNode(15);
    treeB2->left->left = createNode(3);
    treeB2->right->right = createNode(20);

    // Tree C with 5 nodes
    struct Node* treeC2 = createNode(50);
    treeC2->left = createNode(30);
    treeC2->right = createNode(70);
    treeC2->left->right = createNode(40);
    treeC2->right->left = createNode(60);

    runTestCase(2, treeA2, treeB2, treeC2);

    // Test Case 3: Empty and non-empty trees
    printf("\nCreating Test Case 3: Empty and non-empty trees\n");

    // Tree A is empty
    struct Node* treeA3 = NULL;

    // Tree B with 1 node
    struct Node* treeB3 = createNode(42);

    // Tree C with 3 nodes
    struct Node* treeC3 = createNode(99);
    treeC3->left = createNode(88);
    treeC3->right = createNode(77);

    runTestCase(3, treeA3, treeB3, treeC3);

    // Free all allocated memory
    freeTree(treeA1);
    freeTree(treeB1);
    freeTree(treeC1);
    freeTree(treeA2);
    freeTree(treeB2);
    freeTree(treeC2);
    // treeA3 is NULL, no need to free
    freeTree(treeB3);
    freeTree(treeC3);

    return 0;
}

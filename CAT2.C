#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node *right;
};

struct Node* make(int d) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = d;
    n->left = n->right = NULL;
    return n;
}

int howmany(struct Node* r) {
    if (!r) return 0;
    return howmany(r->left) + 1 + howmany(r->right);
}

void show(struct Node* r) {
    if (r) {
        show(r->left);
        printf("%d ",r->data);
        show(r->right);
    }
}

void check(struct Node *x, struct Node *y, struct Node *z) {
    int a = howmany(x), b = howmany(y), c = howmany(z);

    printf("Tree A: %d\nTree B: %d\nTree C: %d\n", a, b, c);

    if (a >= b && a >= c) {
        printf("Largest is A (%d)\nNodes: ",a);
        show(x);
    } else if (b >=a && b >=c) {
        printf("Largest is B (%d)\nNodes: ",b);
        show(y);
    } else {
        printf("Largest is C (%d)\nNodes: ",c);
        show(z);
    }
    printf("\n\n");
}

void cleanup(struct Node* r) {
    if (r) {
        cleanup(r->left);
        cleanup(r->right);
        free(r);
    }
}

int main() {
    struct Node* a1 = make(1);
    a1->left = make(2);
    a1->right = make(3);
    a1->left->left = make(4);
    a1->left->right = make(5);
    a1->right->left = make(6);
    a1->right->right = make(7);

    struct Node* b1 = make(10);
    b1->left = make(20);
    b1->right = make(30);

    struct Node* c1 = make(100);
    c1->left = make(200);
    c1->right = make(300);
    c1->left->left = make(400);
    c1->left->right = make(500);

    printf("  Test 1 \n");
    check(a1, b1, c1);

    struct Node* a2 = make(5);
    a2->left = make(3);
    a2->right = make(7);

    struct Node* b2 = make(10);
    b2->left = make(5);
    b2->right = make(15);
    b2->left->left = make(3);
    b2->right->right = make(20);

    struct Node* c2 = make(50);
    c2->left = make(30);
    c2->right = make(70);
    c2->left->right = make(40);
    c2->right->left = make(60);

    printf(" Test 2 \n");
    check(a2, b2, c2);

    struct Node* a3 = NULL;
    struct Node* b3 = make(42);
    struct Node* c3 = make(99);
    c3->left = make(88);
    c3->right = make(77);

    printf("   Test 3  \n");
    check(a3, b3, c3);

    cleanup(a1); cleanup(b1); cleanup(c1);
    cleanup(a2); cleanup(b2); cleanup(c2);
    cleanup(b3); cleanup(c3);

    return 0;
}

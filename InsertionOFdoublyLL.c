//NSERTION AT FRONT
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct node *prev;
};
struct Node *createNode(data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    temp -> prev = NULL;
};
struct Node *InsertAtFront(struct Node *head, int data)
{
    struct Node *temp = createNode(data);
    temp -> next = head;
    if(head != NULL)
    {
        head -> prev = temp;
    }
    return temp;
};
void printList(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d \n", head -> data);
        head = head -> next;
    }

}
int main()
{
    struct Node* head = createNode(2);
    head -> next = createNode(3);
    head -> next -> prev = head;
    head -> next -> next = createNode(4);
    head -> next -> next -> prev = head;

    printf("Original List: \n");
    printList(head);

    printf("Current Array: \n");
    int data = 1;
    head = InsertAtFront(head,data);
    printList(head);
}
//INSERTION AT THE END
// C Program to insert a node at the end of doubly linked list

#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node with the given data
struct Node *createNode(int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the end of the doubly linked list
struct Node* insertEnd(struct Node *head, int new_data) {
    struct Node *new_node = createNode(new_data);

    // If the linked list is empty, set the new node as the head
    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        // Set the next of last node to new node
        curr->next = new_node;
        // Set prev of new node to last node
        new_node->prev = curr;
    }

    return head;
}

void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {

    // Create a hardcoded doubly linked list:
    // 1 <-> 2 <-> 3
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;

    // Print the original list
    printf("Original Linked List: ");
    printList(head);

    // Insert a new node with data 4 at the end
    printf("Inserting Node with data 4 at the end: ");
    head = insertEnd(head, 4);

    // Print the updated list
    printList(head);

    return 0;
}
//INSERTION AT A SPECIFIC POSITION
// C Program to insert a node at a given position

#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node with the given data
struct Node *createNode(int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at a given position
struct Node* insertAtPosition(struct Node *head, int pos, int new_data) {
    // Create a new node
    struct Node *new_node = createNode(new_data);

    // Insertion at the beginning
    if (pos == 1) {
        new_node->next = head;

        // If the linked list is not empty, set the prev of head to new node
        if (head != NULL) {
            head->prev = new_node;
        }

        // Set the new node as the head of linked list
        head = new_node;
        return head;
    }

    struct Node *curr = head;

    // Traverse the list to find the node before the insertion point
    for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr->next;
    }

    // If the position is out of bounds
    if (curr == NULL) {
        printf("Position is out of bounds.\n");
        free(new_node);
        return head;
    }

    // Set the prev of new node to curr
    new_node->prev = curr;

    // Set the next of new node to next of curr
    new_node->next = curr->next;

    // Update the next of current node to new node
    curr->next = new_node;

    // If the new node is not the last node, update the prev of next node to new node
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }

    // Return the head of the doubly linked list
    return head;
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {

    // Create a hardcoded doubly linked list:
    // 1 <-> 2 <-> 4
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(4);
    head->next->next->prev = head->next;

    // Print the original list
    printf("Original Linked List: ");
    printList(head);

    // Insert new node with data 3 at position 3
    printf("Inserting Node with data 3 at position 3: ");
    int data = 3;
    int pos = 3;
    head = insertAtPosition(head, pos, data);

    // Print the updated list
    printList(head);

    return 0;
}


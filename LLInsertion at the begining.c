#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
};
struct Node*  InsertNodeAtBeginning(struct Node* head , int data)
{
    struct Node* temp = createNode(data);
    temp -> next = head;
    return temp;
}
void printList(struct Node* head)
{
    while(head != NULL)
    {
        printf("%d\n", head -> data);
        head = head -> next;
    }
}
int main()
{
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);

    printf("Original List \n");
    printList(head);

    printf("After Inserting At the front \n");
    int data = 9;
    head = InsertNodeAtBeginning(head, data);
    printList(head);

}


#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;

};
void TraverseValues(struct Node* head)
{
    while(head != NULL){
        printf("%d\n", head -> data);
        head = head -> next;
    }


}
int main()
{
    struct Node* head = createNode(10);
    head -> next = createNode(20);
    head -> next -> next = createNode(30);
    head -> next -> next -> next = createNode(40);

    TraverseValues(head);
}

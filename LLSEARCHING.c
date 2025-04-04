#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool  SearchKey(struct Node* head, int key)
{
    while(head != NULL){
        if(head -> data == key)
            return true;

        head = head -> next;
    }
    return false;

}
int main()
{
    struct Node* head = createNode(1);
    head -> next = createNode(2);
    head -> next -> next = createNode(3);
    head -> next -> next -> next = createNode(4);

    int key = 2;

    if(SearchKey(head, key)){
        printf("YES");
       }else{
        printf("NO");
       }

}

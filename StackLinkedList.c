#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
void push(int value)
{
    struct stack *temp =  (struct stack*)malloc(sizeof(struct stack));
    temp -> data = value;
    temp -> next = NULL;
     if(top == NULL)
     {
         top = temp;
     }else
     {
         temp -> next = top;
         top = temp;
     }
}
void pop()
{
    if(top == NULL)
    {
        printf("The Stack Is Empty!1");
    }else
    {
        printf("%d ", top -> data);
        struct stack *temp = top;
        top = top->next;
        free(temp);
    }
}
void peek()
{
        if (top == NULL) {
        printf("The Stack Is Empty!\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    peek();
    return 0;
}

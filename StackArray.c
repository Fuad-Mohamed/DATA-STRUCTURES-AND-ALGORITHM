#include<stdio.h>
#define SIZE 5
#include <stdbool.h>
int stack[SIZE];
int top = -1;
bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == SIZE - 1;
}

void push(int value)
{
    if(isFull())
    {
        printf("The Stack Is Full!!");
    }else{
        top++;
        stack[top] = value;
      printf("Pushed: %d\n", value);
    }
}
void pop()
{
    if(isEmpty())
    {
        printf("The Stack is Empty!!!");
    }else
    {
        printf("Popped: %d\n", stack[top]);
        top--;
    }
}
void peek()
{
    if(isEmpty())
    {
     printf("The Stack is Empty!!!");
    }else
    {
        printf("%d", stack[top]);
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); // Should print "The Stack Is Full!!"

    peek();

    pop();
    pop();


    pop();
    pop();
    pop();
    pop(); // Should print "The Stack is Empty!!!"

    return 0;
}

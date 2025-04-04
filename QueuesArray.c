#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if(rear + 1 == SIZE)
    {
        printf("The Queue Is FULL!!");
    }else if(rear == -1 && front == -1)
    {
        rear++;
        queue[rear] = value;
        front++;
    }
    else
    {
       rear++;
        queue[rear] = value;
    }
}
bool isEmpty()
{
    if(rear == -1 && front == -1)
    {
        return true;
    }
}
void dequeue()
{
    if(isEmpty())
    {
        printf("The Queue is empty!!");
    }else if (front == rear)
    {
        front = -1;
        rear = -1;
    }else{
        front++;
    }
}

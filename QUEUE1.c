#include<stdio.h>
struct Queue{
    int data;
    struct Queue *next
};
struct Queue *front =NULL;
struct Queue *rear = NULL;
void enqueue(int value)
{
    struct Queue *temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp -> data = value;
    temp -> next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = temp;
        rear = temp;
    }else
    {
        rear -> next = temp;
        rear = temp;
    }
}
void dequeue()
{
    if(isEmpty())
    {
        printf("You Cannot delete an Empty Queue!!");
    }else(front == rear)
    {
        struct Queue *temp = front;
        front = NULL;
        rear = NULL;
    }else
    {
        struct Queue *temp = front;
        front = front -> next;
    }
}

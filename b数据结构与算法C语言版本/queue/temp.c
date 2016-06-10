#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define Element int
typedef struct node
{
    Element data;
    struct node * next;
} node;

typedef node * Ptrnode;

typedef struct quene
{
    int size;
    node * rear;
    node * front;
} Queue;

typedef Queue * Ptrqueue;

Queue * Queue_Creat(void)
{
    Ptrqueue que = (Ptrqueue)malloc(sizeof(Queue));
    que->front = que->rear = NULL;
    que->size = 0;
    return que;
}

Ptrqueue intoqueue(Ptrqueue que, Element data)
{
    Ptrnode newnode = (Ptrnode)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    assert(que != NULL);
    if(que->front ==  NULL)
    {
        que->size++;
        que->rear = que->front = newnode;
    }
    else
    {
        que->size++;
        que->rear->next = newnode;
        que->rear = newnode;
    }
    return que;
}

Ptrqueue delqueue(Ptrqueue que, Element * data)
{
    assert(que != NULL);
    if(que->front == NULL)
    {
        printf("Queue is empty\n");
        return que;
    }
    else
    {
        *data = que->front->data;
        que->front = que->front->next;
        que->size--;
    }
    return que;
}
void PrintQueue(Ptrqueue que)
{
    assert(que != NULL);
    Ptrnode temp = que->front;
    printf("have %d data:",que->size);
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("end\n");
}

int main()
{
    Element data = 0;
    Ptrqueue  q = Queue_Creat();
    intoqueue(q, 5);
    intoqueue(q, 9);
    intoqueue(q, 6);
    PrintQueue(q);
    delqueue(q, &data);
    PrintQueue(q);
    printf("%d ",data);
    delqueue(q, &data);
    delqueue(q, &data);PrintQueue(q);
}

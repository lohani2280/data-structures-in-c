#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    unsigned int capacity;
    int size;
    int front;
    int rear;
    int* array;
};

typedef struct Queue Queue;

Queue* CreateQueue(unsigned capacity)
{
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->size = 0;
  queue->front = 0;
  queue->rear = capacity-1;
  queue->array = (int*)malloc(queue->capacity*sizeof(int));
  return queue;
}

int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void Enqueue(Queue* queue , int item)
{
    if(isFull(queue))
        return;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size+1;
    printf("%d enqueued to queue\n" , item);
}

int Dequeue(Queue* queue)
{
    if(isEmpty(queue))
        return;
    int item = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size = queue->size-1;
    return item;
}

int Front(Queue* queue)
{
    if(isEmpty(queue))
       return;
    return queue->array[queue->front];
}

int Rear(Queue* queue)
{
    if(isEmpty(queue))
        return;
    return queue->array[queue->rear];
}

int main()
{
    Queue* queue;
    queue = CreateQueue(5);
    Enqueue(queue,5);
    Enqueue(queue,6);
    Enqueue(queue,7);
    Enqueue(queue,8);
    Enqueue(queue,9);
    //Enqueue(queue,4);
    //Enqueue(queue,3);
    printf("%d\n",Front(queue));
    printf("%d\n",Rear(queue));
    printf("%d\n",Dequeue(queue));
    printf("%d\n",Dequeue(queue));
    printf("%d\n",Front(queue));
    printf("%d\n",Rear(queue));

    return 0;
}

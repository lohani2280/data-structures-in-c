#include<stdio.h>
#define SIZE 5


struct priority_queue
{
   int data;
   int priority;
};

typedef struct priority_queue Pqueue;

void Push(Pqueue* q , int* r , int* c)
{
   int a,p;

   if(*r == SIZE-1)
   {
       printf("queue is full\n");
       return;
   }

   printf("Enter an element:: ");
   scanf("%d",&a);
  // printf("\n");
   printf("Enter its priority ::");
   scanf("%d",&p);
   (*r)++;
   q[(*r)].data = a;
   q[(*r)].priority= p;
   (*c)++;
}

void Pop(Pqueue* q, int* f, int* r,int* c)
{
    int max,i;
    Pqueue removed;
 if(*f == SIZE-1)
  {
      printf("queue is empty\n");
      return;
  }

  max = q[*f].priority;
  for(i=(*f);i<=(*r);i++)
  {
    if(q[i].priority > max)
      {
          max = q[i].priority;
          removed = q[i];
      }
  }


  printf("Poped element :: %d\n" , removed.data);
  //(*f) = ((*f) + 1) % SIZE;
  (*f)++;
  (*c)--;
}

void Display(Pqueue* q , int f , int r)
{
    int i;
    printf("Elements in the queue :: ");
    for(i=(f) ; i<=(r) ; i++)
    {
        printf("%d", q[i].data);
    }
    printf("\n");
}

int main()
{

    Pqueue queue[SIZE];
    int front = 0;
    int rear = -1;
    int count = 0;
    int n = 5;
    while(n)
    {
        printf("Press 1. to Push\n");
        printf("Press 2. to Pop\n");
        printf("Press 3. to Display\n");
        printf("Press 0. to Exit\n");
        printf("Enter your choice :: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            Push(queue,&rear,&count);
            break;
        case 2:
            Pop(queue,&front,&rear,&count);
            break;
        case 3:
            Display(queue,front,rear);
            break;
        }
    }
    return 0;
}

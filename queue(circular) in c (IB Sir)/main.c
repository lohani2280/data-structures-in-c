#include<stdio.h>
#define SIZE 5

void Push(int* q , int* r , int* c)
{
   int a;
   if(*c == SIZE)
   {
       printf("queue is full\n");
       return;
   }
   printf("Enter an element :: ");
   scanf("%d",&a);
   (*r) = ((*r)+1) % SIZE;
   q[(*r)] = a;
   (*c)++;
}

void Pop(int* q, int* f, int* c)
{
  if(*c == 0)
  {
      printf("queue is empty\n");
      return;
  }

  printf("Poped value :: %d\n" , q[*f]);
  (*f) = ((*f) + 1) % SIZE;
  (*c)--;
}

void Display(int* q , int f , int r)
{
    int i;
    printf("Elements in the queue :: ");
    for(i=(f) ; i<=(r) ; i++)
    {
        printf("%d", q[i]);
    }
    printf("\n");
}

int main()
{
    int queue[SIZE];
    int front = 0;
    int rear = -1;
    int count = 0;
    int n = 5;
    while(n)
    {
        printf("Press 1. to Push\n");
        printf("Press 2. to Pop\n");
        printf("Press 3. to Display\n");
        printf("Press 4. to Exit\n");
        printf("Enter your choice :: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            Push(queue,&rear,&count);
            break;
        case 2:
            Pop(queue,&front,&count);
            break;
        case 3:
            Display(queue,front,rear);
            break;
        }
    }
    return 0;
}

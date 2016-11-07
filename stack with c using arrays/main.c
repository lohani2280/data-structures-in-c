#include<stdio.h>
#define SIZE 5

void push(int* s, int* t)
{
  int a;
  if(*t == SIZE-1)
  {
      printf("No more elements can be inserted");
      return;
  }
  else
  {
  printf("Enter number to be inserted in stack ");
  scanf("%d",&a);
  (*t)++;
  s[*t]=a;
  }
}

void pop(int* s, int* t)
{
    printf("%d",s[*t]);
    (*t)--;
}

void display(int* s, int t)
{
    int i;
    for(i=0;i<=t;i++)
    {
        printf("%d",s[i]);
    }

}

int main()
{
    int stack[SIZE];
    int top= -1;
    int n;

    while(n)
    {
        printf("Enter 1.for inserting an element in the stack\n ");
        printf("Enter 2. for removing an element from the stack\n ");
        printf("Enter 3. for displaying elements in the stack\n ");
        printf("Enter 0. for exit\n ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            push(stack,&top);
            break;
        case 2:
            pop(stack,&top);
            break;
        case 3:
            display(stack,top);
            break;
        }
    }
   return 0;
}

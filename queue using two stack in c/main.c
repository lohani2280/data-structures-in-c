#include<stdio.h>
#define SIZE 50

void Push(int* s , int* t , int y)
{
    if((*t) == SIZE-1)
    {
        printf("Stack Full\n");
        return;
    }
      s[++(*t)] = y;
}


int Pop_Stack(int *s , int* t)
{
    int x;
    if((*t) == -1)
    {
        printf("Stack Is Empty\n");
        return 0;
    }
    x = s[*t];
    (*t)--;
    return x;
}

void Display(int* s1 , int* s2 , int* t1 , int* t2)
{
    if((*t2) > -1)
    {
       int i;
       for(i=(*t2);i>=0;i--)
                printf("%d",s2[i]);
    }
    if((*t1) > -1)
    {
        int j;
        for(j=0 ; j<=(*t1) ; j++)
            printf("%d",s1[j]);
    }

    printf("\n");
}

void Pop_Queue(int* s1 , int* s2 , int* t1, int* t2)
{
    if((*t2) > -1)
    {
        printf("%d\n",Pop_Stack(s2,t2));
    }
    else
    {
      while((*t1) > -1)
      {
        Push(s2, t2 , Pop_Stack(s1,t1));
      }
      printf("%d\n",Pop_Stack(s2,t2));
    }
}


int main()
{
    int stack1[SIZE];
    int stack2[SIZE];
    int top1 = -1;
    int top2 = -1;
    int n=5;
    int a;
    while(n)
    {
        printf("Press 1. to Push\n");
        printf("Press 2. to Pop\n");
        printf("Press 3. to display\n");
        printf("Press 0. to exit\n");
        printf("Enter Your Choice :: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("Enter a no. :: ");
            scanf("%d",&a);
            Push(stack1,&top1,a);
            break;
        case 2:
            Pop_Queue(stack1, stack2 , &top1 , &top2);
            break;
        case 3:
            Display(stack1 , stack2 , &top1 , &top2);
            break;
        }
    }
    return 0;
}

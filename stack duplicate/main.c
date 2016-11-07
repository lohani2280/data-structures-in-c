#include<stdio.h>
#define SIZE 50

void push(int* s, int* t, int y)
{
  int a;
  if(*t == SIZE-1)
  {
      printf("No more elements can be inserted");
      return;
  }
  (*t)++;
  s[*t]=y;
}


int pop(int* s, int* t)
{
    int x= s[*t];
    (*t)--;
    return x;
}

void display(int* s, int t)
{
    int i;
    printf("Elements in the stack :: ");
    for(i=t;i>=0;i--)
    {
        printf("%d",s[i]);
    }
    printf("\n");

}

void reverse_stack(int* s, int* t)
{
    int i,j;
    for(i = (*t) , j=0 ; i>j ; i--, j++)
    {
        int x;
        x=s[i];
        s[i] = s[j];
        s[j] = x;
    }
}

void duplicatestack(int* s,int* t)
{
    int i,k;
    int j=0;
    int arr[SIZE];
    int count;
    int duplicate_stack[SIZE];
    int new_top = -1;
    while((*t) > -1)
    {
        count = 0;
        arr[j] = pop(s,t);
        //printf(" yo = %d" , arr[j]);
        for(i=0; i<=j; i++)
        {
            if(arr[i] == arr[j])
                count++;
        }
        if(count == 1)
          push(duplicate_stack , &new_top , arr[j]);

        /*for(i=0;i<=j;i++)
            printf("yo = %d", arr[i]);
        */
        j++;
    }

    //display(duplicate_stack , new_top);


    for(k=j;k>=0;k--)
    {
        push(s,t,arr[k]);
    }


    reverse_stack(duplicate_stack , &new_top);
    printf("DupicateStack :: ");
    for(k = new_top ; k>=0 ; k--)
    {
        printf("%d", duplicate_stack[k]);
    }
    printf("\n");

}

int main()
{
    int stack[SIZE];
    int top= -1;
    int n;
    int a;

    while(n)
    {
        printf("Enter 1. for inserting an element in the stack\n");
        printf("Enter 2. for removing an element from the stack\n");
        printf("Enter 3. for displaying elements in the stack\n");
        //printf("Enter 4. to see the topmost element\n");
        printf("Enter 4. to create a duplicate stack\n");
        printf("Enter 0. for exit\n");
        printf("Enter your choice :: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("Enter an Element :: ");
            scanf("%d", &a);
            push(stack,&top,a);
            break;
        case 2:
            pop(stack,&top);
            break;
        case 3:
            display(stack,top);
            break;
        case 4:
      //      int* new_top;
            duplicatestack(stack,&top);
            break;
        }

    }
   return 0;
}

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50

void Push(int* s, int* t, int x)
{
    if(s[*t]==SIZE-1)
    {
        printf("Stack is Full");
        return;
    }

    s[++(*t)]=x;
}


int Pop(int* s, int* t)
{
    if(s[*t] == -1)
    {
        printf("Stack is Empty");
        return 0;
    }

    return s[(*t)--];
}


int isoperator(char symbol)
{
    if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        return 1;
    else
        return 0;
}


void Evaluate_Prefix(int* s, int* t, char* st)
{
    int i,x,y;
    for(i=strlen(st);i>=0;i--)
    {
        if(isdigit(st[i]))
            Push(s,t,st[i] - '0');

        if(isoperator(st[i]))
        {
             x= Pop(s,t);
             y= Pop(s,t);

           switch(st[i])
           {
           case '+':
            Push(s,t,x+y);
            break;
           case '-':
            Push(s,t,x-y);
            break;
           case '*':
            Push(s,t,x*y);
            break;
           case '/':
            Push(s,t,x/y);
            break;
           }
        }
    }
    printf("%d", Pop(s,t));
}

int main(void)
{
    int stack[SIZE];
    char str[SIZE];
    int top=-1;
    printf("Enter a Prefix Expression:: ");
    gets(str);
    Evaluate_Prefix(stack,&top,str);
    return 0;
}

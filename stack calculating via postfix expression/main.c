#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50

void Push(char* s, int* t, int c)
  {
      if((*t)==SIZE-1)
      {
          printf("Stack  Full\n");
          return;
      }

      else
      {
          //(*t)++;
          s[++(*t)]=c;
      }
  }


int Pop(char* s,int* t)
{
    if((*t)==-1)
    {
        printf("Stack Empty\n");
        return 0;
    }
    else
    {
      // c= s[(*t)--];
       //(*t)--;
       //return c;
       return s[(*t)--];
    }
}

void Display(char* s, int t)
{
    int i;
    for(i=t;i>=0;i--)
    {
        printf("%c ",s[i]);
    }
}

int Cal_Postfix(char* str,char* s, int* t)
{
    int i,x,y;
    i=0;
    while(str[i]!='\0')
    {
       if(isdigit(str[i]))
        Push(s,t,str[i] - '0');
        else
        {
            //if(str[i]=='*' ||  str[i]=='/' ||  str[i]=='+' ||  str[i]=='-')

              x=Pop(s,t);
              y=Pop(s,t);
              switch(str[i])
              {
              case '/':
                Push(s,t,x/y);
                //res=x/y;
                //res=z - '0';
                break;
              case '*':
                Push(s,t,x*y);
                //res=x*y;
                //res=z - '0';
                break;
              case '+':
                Push(s,t,x+y);
                //res=x+y;
                //res=z - '0';
                break;
              case '-':
                Push(s,t,x-y);
                //res=x-y;
                //res=z - '0';
                break;
              }
        }
        i++;
    }
    return Pop(s,t);
}

int main()
{
      char str[SIZE];
      char stack[SIZE];
      int top= -1;
      printf("Enter a String of postfix expression:: ");
      gets(str);
      printf("result= %d",Cal_Postfix(str,stack,&top));
      return 0;
}

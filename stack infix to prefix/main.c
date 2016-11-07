#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 50


void Push(char* s, int* t, char c)
{
    if(s[*t]==SIZE-1)
        {
            printf("Stack is Full");
            return;
        }
     (*t)++;
     s[*t]= c;
}


char Pop(char* s, int* t)
{
    if((*t)== -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    return s[(*t)--];
}

void Display(char* s, int t)
{
    int i;
    for(i=t;i>=0;i--)
        printf("%c ", s[i]);
}

int Isoperator(char symbol)
{
    if(symbol=='+'|| symbol=='-'|| symbol=='*'|| symbol=='/'|| symbol=='^')
        return 1;
    else
        return 0;
}


int Precedence(char symbol)
{
    if(symbol == '^')
        return 3;
    if(symbol == '*' || symbol == '/')
        return 2;
    if(symbol == '+' || symbol == '-')
        return 1;
}




void Convert_Postfix(char* s, int* t, char* st, char* Postfix_Array)
{
  int j=0;
  int i=0;
  int k;
  while(st[i]!='\0')
  {
      if(st[i]=='(')
            {
                Push(s,t,st[i]);
            }


      if(isdigit(st[i]))
            {
                Postfix_Array[j]= st[i];
                j++;
            }

      if(Isoperator(st[i]))
      {
          if(Isoperator(s[*t]))
          {
           while (Precedence(s[*t]) >= Precedence(st[i]))
             {
              Postfix_Array[j++] = Pop(s,t);
             }
          }
        Push(s,t,st[i]);
      }


      if(st[i]==')')
       {
           while(s[(*t)]!='(')
           {
               Postfix_Array[j]=Pop(s,t);
               j++;
           }
           char ch= Pop(s,t);
       }
     i++;
  }

printf("Required Prefix Expression is :: ");
  for(k=j;k>=0;k--)
    printf("%c ",Postfix_Array[k]);

}

/*
void Reverse_String(char* st)
{
    int i,j;
    for(i=0,j=strlen(st) ; j>i ; i++,j--)
    {
        char x;
        x=st[i];
        st[i]=st[j];
        st[j]=x;
    }
    st[strlen(st)+1]='\0';
}
*/

void step(char* st)
{
    int i;
    i=0;
    while(st[i]!='\0')
    {
        if(st[i] == '(')
        {
            st[i] = ')';
        }

        else if(st[i] == ')' )
        {
            st[i] = '(';
        }
       i++;
    }
}

void Print_String(char* st)
{
    int i;
    printf("Required string :: ");
    i=0;
    while(st[i]!='\0')
    {
        printf("%c",st[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    char str[SIZE];
    char stack[SIZE]="";
    char Postfix_Array[SIZE];
    int top=-1;
    printf("Enter a Infix Expression:: ");
    gets(str);
    Print_String(str);
    strrev(str);
    Print_String(str);
    step(str);
    Print_String(str);
    Convert_Postfix(stack,&top,str,Postfix_Array);
    //strrev(str);
    //Print_String(str);
 //   Reverse_String(str);
    return 0;
}

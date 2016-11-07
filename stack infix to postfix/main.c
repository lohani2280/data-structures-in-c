#include<stdio.h>
#include<ctype.h>
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
    //            printf("( loop\n");
                Push(s,t,st[i]);
            }


      if(isdigit(st[i]))
            {
      //          printf("digit loop\n");
                Postfix_Array[j]= st[i];
                j++;
            }

      if(Isoperator(st[i]))
      {
          //int count;
        //  printf("operator loop\n");
          //printf("%d\n",Precedence(s[*t]));
          //printf("%d\n",Precedence(st[i]));
          if(Isoperator(s[*t]))
          {
           while (Precedence(s[*t]) >= Precedence(st[i]))
             {
              Postfix_Array[j++] = Pop(s,t);
            //  count++;
             }
          }
        //printf("yo = %c\n",st[i]);
        Push(s,t,st[i]);
        //printf("Printing current stack\n");
        //Display(s,(*t));
        //printf("\n");
         // printf(" operator count= %d",count);
      }

/*
      if(Isoperator(st[i]))
      {
          char x;
          x= Pop(s,t);  //
          while(Isoperator(x) && Precedence(x)> Precedence(st[i]))
          {
              Postfix_Array[j]=x;
              j++;
              //if((*t)!=0)
              x=Pop(s,t);
               //printf("%d  ",j);
          }
           Push(s,t,x);
           Push(s,t,st[i]);
           printf("c\n");
      }
*/



      if(st[i]==')')
       {
       //    printf(") loop\n");
           while(s[(*t)]!='(')
           {
               Postfix_Array[j]=Pop(s,t);
          //     printf("postfix_Element = %c\n",Postfix_Array[j]);
               j++;
               //(*t)--;
           }
           char ch= Pop(s,t);
       }
     i++;
  }
/*

  while((*t)!=-1)
  {
      Postfix_Array[j]=Pop(s,t);)()()dcscxzcds
      j++;
  }
*/

  //printf("%d\n ",j);
printf("Required Postfix Expression is :: ");
  for(k=0;k<j;k++)
    printf("%c ",Postfix_Array[k]);

}


int main()
{
    char str[SIZE];
    char stack[SIZE]="";
    char Postfix_Array[SIZE];
    int top=-1;
    printf("Enter a Infix Expression:: ");
    gets(str);
    Convert_Postfix(stack,&top,str,Postfix_Array);
    return 0;
}

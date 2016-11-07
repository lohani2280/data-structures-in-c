#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50


struct Snode
{
    char data;
    struct Snode* next;
};

typedef struct Snode node;

void Push_String(node** top_ref, char* str)
{
   int i;
   for(i=0;i<strlen(str);i++)
   {
     node* new_node=(node*)malloc(sizeof(node));
     new_node->data = *(str+i);
     new_node->next=(*top_ref);
     (*top_ref)=new_node;
   }
   str[strlen(str)+1]=='\0';
}

void check_palindrome(node* top)
{
    node* temp=top;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
}

void Display(node* top)
{
    if(top==NULL)
        return;
    printf("%c",top->data);
    Display(top->next);
}

int main()
{
    node* top=NULL;
    char string[SIZE];
    gets(string);
    Push_String(&top,string);
    Display(top);
    check_palindrome(top);
}

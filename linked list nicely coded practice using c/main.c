#include<stdio.h>
#include<stdlib.h>

struct LinkedList
{
    int data;
    struct node* next;
};

typedef struct LinkedList node;

void Push_back(node** head_ref,int new_data)
{
    node* temp;
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data= new_data;
    new_node->next=NULL;

    if(*head_ref==NULL)
    {
        *head_ref=new_node;
    }

    else
    {
       temp=*head_ref;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=new_node;

    }
}

/*void Push_front(node** head_ref, int new_data)  // MY CODE. DONT KNOW IF ITS CORRECT
{
    node* new_node= (node*)malloc(sizeof(node));
    new_node->data=new_data;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        (*head_ref)->next=NULL;
    }

    else
    {
       node* temp;
       temp=*head_ref;
       *head_ref=new_node;
       (*head_ref)->next=temp;
    }
}
*/
void Push_front(node** head_ref, int new_data)   //Standard meethod.
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void print_list(node* n)  //Iterative method
{
    while(n!=NULL)
    {
        printf("%d",n->data);
        n=n->next;
    }

}

/*
void print_list(node* n) // Recursive way
{
    if(n==NULL)
    {
        return;
    }
    printf("d",n->data);
    print_list(n->next);
}

*/
void Reverse_print(node* n)
{
    if(n==NULL)
    {
        return;
    }
    Reverse_print(n->next);
    printf("%d",n->data);
}

int  Size(node* n)  //ITERATIVE WAY
{
    int count=0;
    while(n!=NULL)
    {

        n=n->next;
        count++;
    }
    return count;
}

/*
int Size(node* n)  //RECURSIVE WAY
{
    if(n==NULL)
        return 0;
    return(1+Size(n->next));
}
*/
void delete(node** head_ref, int key)
{
    node* temp;
    node* prev;
    temp=*head_ref;
    if(*head_ref!=NULL&&(*head_ref)->data==key)
    {
        *head_ref=(*head_ref)->next;
        free(temp);
    }

    else
  {
    while(temp->data!=key)
    {
       prev=temp;
       temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
  }
}

void Insert_After(node* prev_node, int new_data)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

int GetNth(node* n, int index)
{
    node* prev;
    int count=0;
    while(n!=NULL)
    {
       prev=n;
       n=n->next;
       count++;
       if(count==index)
        break;
    }
    return prev->data;

}

void deleteList(node** head_ref)
{
    free((*head_ref));
    (*head_ref)=NULL;
}


int main()
{
  int len;
  int Nth_node_data;
  node* head=NULL;
  Push_back(&head, 5);
  Push_front(&head,6);
  Push_front(&head,8);
  Push_front(&head,7);
  print_list(head);
  printf("\n");
  Reverse_print(head);
  delete(&head,6);
  printf("\n");
  print_list(head);
  printf("\n");
  len=Size(head);
  printf("%d",len);
  printf("\n");
  Push_back(&head, 1);
  Push_back(&head, 0);
  Push_back(&head, 4);
  print_list(head);
  printf("\n");
  Nth_node_data=GetNth(head, 4);
  printf("%d",Nth_node_data);

  return 0;
}

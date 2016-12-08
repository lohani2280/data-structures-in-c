// INCOMPLETE = DELETE A NODE WITH TWO CHILDREN.
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

void Insert(node** n , int value)
{
    if((*n) == NULL)
    {
       (*n) = (node*)malloc(sizeof(node));
       (*n)->data = value;
       (*n)->left = NULL;
       (*n)->right = NULL;
    }

    else if((*n)->data < value)
    {
        Insert(&(*n)->right , value);
    }

    else if((*n)->data > value)
    {
        Insert(&(*n)->left , value);
    }

    else
    {
        printf("\n Duplicate Data \n");
    }
}

void Inorder(node* n)
{
    if(n == NULL)
    {
        return;
    }
    Inorder(n->left);
    printf("%d",n->data);
    Inorder(n->right);
}


void Search(node** r , int val , node** p , node** t)
{
  //(*p) = (*r);

  if((*r)->data == val)
  {
    (*t) = (*r);
    return;
  }

  (*p) = (*r);

  if((*r)->data > val)
   {
       Search(&(*r)->left,val,p,t);
   }

   if((*r)->data < val)
   {
       Search(&(*r)->right,val,p,t);
   }
}

node* min(node* n)
{
    if(n->left == NULL)
        return n;
    else
         min(n->left);
}


void Delete(node** r , int val)
{
    node* parent = NULL;
    node* target = NULL;

    if((*r) == NULL)
    {
        printf("\n Tree Does'nt Exist \n");
        return;
    }

    Search(r,val,&parent,&target);

    if(target->left == NULL && target->right == NULL)
    {
       if(parent->left == target)
            parent->left = NULL;
       else
            parent->right = NULL;
       free(target);
       return;
    }

    if(target->left == NULL && target->right != NULL)
    {
        if(parent->left == target)
            parent->left = target->right;
        else
            parent->right = target->right;

        free(target);
        return;
    }

     if(target->left != NULL && target->right == NULL)
    {
        if(parent->left == target)
            parent->left = target->left;
        else
            parent->left = target->left;

        free(target);
        return;
    }

    if(target->left != NULL && target->right != NULL)
    {
       // Find minimum element in the right subtree of the node to be removed.
      // parent = target;
       node* temp = target->right;;
       while(temp->left != NULL)
       {
        // parent = temp;
         temp = temp->left;
       }

       target->data = temp->data;
       //target = temp;
      }
}



int main(void)
{
 node* root = NULL;
 int n = 1;
 int a,del;

 while(n)
 {
     printf("Press 1. to INSERT\n");
     printf("Press 2. for INORDER TRAVERSAL\n");
     printf("Press 3. to DELETE\n");
     printf("Press 0. to EXIT\n");
     printf("Enter Your choice :: ");
     scanf("%d",&n);
     printf("\n");
     switch(n)
     {
     case 1:
        printf("Enter number to insert :: ");
        scanf("%d",&a);
        Insert(&root,a);
        break;
     case 2:
        Inorder(root);
        break;
     case 3:
        printf("Enter the number to be deleted :: ");
        scanf("%d",&del);
        Delete(&root , del);
     }

     printf("\n");
 }
 return 0;
}

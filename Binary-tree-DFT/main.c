#include<stdio.h>
#include<stdlib.h>

struct BinaryTree
{
   int data;
   struct BinaryTree* left;
   struct BinaryTree* right;
};

typedef struct BinaryTree node;

node* NewNode(int value)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void PrintPreorder(node* n)
{
       if(n == NULL)
          return;

       printf("%d" , n->data);
       PrintPreorder(n->left);
       PrintPreorder(n->right);
}

void PrintPostorder(node* n)
{
    if(n == NULL)
        return;

    PrintPostorder(n->left);
    PrintPostorder(n->right);
    printf("%d" , n->data);
}

void PrintInorder(node* n)
{
    if(n == NULL)
        return;
    PrintInorder(n->left);
    printf("%d" , n->data);
    PrintInorder(n->right);
}

-

int main(void)
{
    node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->left->right->left = NewNode(6);
    root->left->right->right = NewNode(7);
    printf("PreOrder traversal :: ");
    PrintPreorder(root);
    printf("\nPostOrder traversal :: ");
    PrintPostorder(root);
    printf("\nInOrder traversal :: ");
    PrintInorder(root);
    return 0;
}

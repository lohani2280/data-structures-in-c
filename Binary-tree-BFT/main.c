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
/*
int Height(node* root)
{
    if(root == NULL)
        return 0;

    int leftheight = Height(root->left);
    int rightheight = Height(root->right);

    if(leftheight > rightheight)
        return leftheight+1;
    else
        return rightheight+1;
}
*/


int Height(node* root)
{
    int leftheight;
    int rightheight;

    if(root == NULL)
        return 0;

    leftheight = 1+Height(root->left);
    rightheight =1+Height(root->right);


    if(leftheight > rightheight)
        return leftheight;
    else
        return rightheight;
}


void PrintGivenlevel(node* n , int level)
{
   if(n == NULL)
        return;
   else if(level == 1)
    printf("%d" , n->data);

   else
   {
       PrintGivenlevel(n->left , level-1);
       PrintGivenlevel(n->right , level-1);
   }
}

void PrintLevelorder(node* root)
{
    int level;
    for(level = 1 ; level <= Height(root) ;  level++)
      PrintGivenlevel(root , level);
}



int main(void)
{
    node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right->left = NewNode(6);
    root->right->right = NewNode(7);
    //root->right->left->right = NewNode(8);
    printf("Level Order Traversal :: ");
    PrintLevelorder(root);
    printf("\n");
    printf("Height of tree :: %d" , Height(root));
    return 0;
}
/*
Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
*/

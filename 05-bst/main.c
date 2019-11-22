#include <stdio.h>
#include <stdlib.h>

struct node
{
   int value;
   struct node *left;
   struct node *right;
};

struct node *createNode(int);
void insertNode(struct node **, int);
void printInorder(struct node *);

int main(int argc, char const *argv[])
{
   int n = 6;
   int numbers[] = {3, 1, 4, 1, 5, 9};

   struct node *root = NULL;

   for (size_t i = 0; i < n; i++)
      insertNode(&root, numbers[i]);

   printInorder(root);

   return 0;
}

struct node *createNode(int value)
{
   struct node *insertee = (struct node *)malloc(sizeof(struct node));
   *insertee = (struct node){value, NULL, NULL};

   return insertee;
}

void insertNode(struct node **rootPtr, int value)
{
   if (*rootPtr == NULL)
      *rootPtr = createNode(value);

   else if (value < (*rootPtr)->value)
      insertNode(&(*rootPtr)->left, value);
   else
      insertNode(&(*rootPtr)->right, value);
}

void printInorder(struct node *root)
{
   if (root == NULL)
      return;

   printInorder(root->left);
   printf("%d\n", root->value);
   printInorder(root->right);
}
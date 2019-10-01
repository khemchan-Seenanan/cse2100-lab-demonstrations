#include <stdio.h>
#include <stdlib.h>

// structure definition for node within singly-linked list
struct node
{
  int value;
  struct node *next;
};

// prototypes for struct node associated algorithms
void insertNode(struct node **, int);
void printList(struct node *);

int main(int argc, char const *argv[])
{
  // create empty list
  struct node *head = NULL;

  // insert value (node) into empty list
  insertNode(&head, 1);

  // insert value (node) into non-empty list
  insertNode(&head, 2);

  printf("%d\n", head->value);
  printf("%d\n", head->next->value);

  return 0;
}

// insertNode implementation
void insertNode(struct node **headPtr, int value)
{
  // if list is empty, declare node in heap and add to end
  if (*headPtr == NULL)
  {
    // memory allocation for struct node in heap
    struct node *insertee = (struct node *)malloc(sizeof(struct node));

    // initialize node's value and next pointer to passed-in value and NULL respectively
    insertee->value = value;
    insertee->next = NULL;

    // add node to end of list
    *headPtr = insertee;
  }
  // non-empty list; search for empty list
  else
  {
    // recursive call, passing address of head for sub-list (think list within list)
    insertNode(&(**headPtr).next, value);
  }
}

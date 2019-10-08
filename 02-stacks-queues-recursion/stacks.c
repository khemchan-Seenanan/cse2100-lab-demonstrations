#include <stdio.h>
#include <stdlib.h>

// structure definition for element within stack
struct element
{
  int value;
  struct element *next;
};

struct stack
{
  struct element *top;
};

// prototypes and crap
struct stack *createStack();
void push(struct stack *, int);
void pop(struct stack *);

int main(int argc, char const *argv[])
{
  // create empty stack
  struct stack *stack = createStack();

  push(stack, 0);
  push(stack, 1);

  pop(stack);

  return 0;
}

// createStack implementation
struct stack *createStack()
{
  struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
  stack->top = NULL;

  return stack;
}

// push implementation
void push(struct stack *stack, int value)
{
  // allocate memory for element
  struct element *element = (struct element *)malloc(sizeof(struct element));

  // initialize value
  element->value = value;

  // initialize next to previous top
  element->next = stack->top;

  // update stack's top to new element
  stack->top = element;
}

void pop(struct stack *stack)
{
  // temporary variable for free-ing
  void *to_free = stack->top;

  // update top of stack to next element;
  stack->top = stack->top->next;

  // perform freeing
  free(to_free);
}
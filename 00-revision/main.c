#include <stdio.h>
#include <string.h>

// function prototypes -implementation found below
int isEven(int x);
int isOdd(int x);

// struct definition for a course
struct course
{
  int number;
  char name[20];
};

// struct definition for student
struct student
{
  // primitive type int
  int usi;

  // primitive type char array (string)
  char name[20];

  // user-defined type course
  struct course courses[5];
};

int main(int argc, char const *argv[])
{
  // declare variable of type struct student
  struct student john;

  // struct variable members manipulation
  john.usi = 1008654;
  strcpy(john.name, "John Smith");

  // struct variable members access
  printf("Student USI: \t%d", john.usi);
  puts("");
  printf("Student name: \t%s", john.name);
  puts("");

  puts("");

  // array declaration
  int n = 3;            // array size
  int xs[] = {3, 1, 4}; // declaration and initialization

  int i;

  // array traversal
  for (i = 0; i < n; i++)
  {
    if (isEven(xs[i]))
    {
      printf("%d is Even\n", xs[i]);
    }
    else
    {
      printf("%d is Odd\n", xs[i]);
    }
  }

  puts("");

  // pointers
  int x = 23;
  int *xptr = &x;

  printf("Value of x: %d\n", x);
  printf("Value of xptr's reference: %d\n", *xptr);
  printf("Address of x: %p\n", &x);
  printf("Value of xptr: %p\n", xptr);

  return 0;
}

int isEven(int x)
{
  if (x % 2 == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isOdd(int x)
{
  return !isEven(x);
}
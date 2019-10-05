#include <stdio.h>

int factorial(int);

int main(int argc, char const *argv[])
{
  int x = 3;
  printf("Factorial:\t%d\n", factorial(x));

  return 0;
}

int factorial(int x)
{
  // base case
  if (x == 0)
    return 1;

  // recursive call, reducing problem
  return x * factorial(x - 1);
}
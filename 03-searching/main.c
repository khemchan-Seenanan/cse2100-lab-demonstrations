#include <stdio.h>
#include <stdbool.h>

#define SIZE 100
#define NOT_FOUND -1

typedef int result;

// prototypes
bool match(int, int);
result linearSearch(int[], int, int);
result binarySearch(int[], int, int);

int main(int argc, char const *argv[])
{
  // declare array
  int integers[SIZE];

  // initialize array with values
  for (int i = 0; i < SIZE; i++)
    integers[i] = i;

  // result _result = linearSearch(integers, SIZE, 23);
  result _result = binarySearch(integers, SIZE, 23);

  if (_result == NOT_FOUND)
    printf("Not found\n");
  else
    printf("Found at %d index\n", _result);

  return 0;
}

bool match(int x, int y)
{
  return x == y;
}

result linearSearch(int integers[], int n, int query)
{
  for (int i = 0; i < n; i++)
    if (match(integers[i], query))
      return i;

  return NOT_FOUND;
}

result binarySearch(int integers[], int n, int query)
{
  int start = 0, end = n - 1, middle_idx;

  while (start <= end)
  {
    // middle index
    middle_idx = start + (end - start) / 2;

    // compare against middle element
    if (match(integers[middle_idx], query))
      return middle_idx;

    // search latter half
    if (query > integers[middle_idx])
      start = middle_idx + 1;
    // search former half
    else
      end = middle_idx - 1;
  }

  return NOT_FOUND;
}
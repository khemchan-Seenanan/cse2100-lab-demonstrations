#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(void *, void *, int);
bool greaterThan(int, int);
bool lessThan(int, int);
void bubbleSort(int[], int, bool (*)(int, int));
void insertionSort(int[], int);

int main(int argc, char const *argv[])
{
  int n = 10;
  int numbers[n];

  for (int i = 0; i < n; i++)
    numbers[i] = i;

  // perform sorting
  // bubbleSort(numbers, n, lessThan);
  // insertionSort(numbers, n);

  for (int i = 0; i < n; i++)
    printf("%d\n", numbers[i]);

  puts("");

  return 0;
}

void swap(void *x, void *y, int size_t)
{
  void *temp = malloc(size_t);
  memcpy(temp, x, size_t);
  memcpy(x, y, size_t);
  memcpy(y, temp, size_t);

  free(temp);
}

bool greaterThan(int x, int y)
{
  return x > y;
}

bool lessThan(int x, int y)
{
  return !greaterThan(x, y);
}

void bubbleSort(int numbers[], int n, bool (*compare)(int x, int y))
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i - 1; j++)
      if ((*compare)(numbers[j], numbers[j + 1]))
        swap(&numbers[j], &numbers[j + 1], sizeof(int));
}

void insertionSort(int numbers[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int j;
    int insertee = numbers[i];

    for (j = i; j > 0 && !(insertee > numbers[j - 1]); j--)
      swap(&numbers[j - 1], &numbers[j], sizeof(int));

    numbers[j] = insertee;
  }
}
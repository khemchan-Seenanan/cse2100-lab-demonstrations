#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *, void *, int);
void bubbleSort(int[], int);

int main(int argc, char const *argv[])
{
  int n = 100000;
  int numbers[n];

  for (int i = n - 1; i >= 0; i--)
    numbers[i] = i;

  // perform bubblesort
  bubbleSort(numbers, n);

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

void bubbleSort(int numbers[], int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (numbers[j] > numbers[j + 1])
        swap(&numbers[j], &numbers[j + 1], sizeof(int));
}
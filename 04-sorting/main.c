#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(void *, void *, int);
bool greaterThan(int, int);
bool lessThan(int, int);
void bubbleSort(int[], int, bool (*)(int, int));
void insertionSort(int[], int, bool (*)(int, int));
void selectionSort(int[], int, bool (*)(int, int));
void mergeSort(int[], int);

int main(int argc, char const *argv[])
{
  int n = 6;
  int numbers[] = {3, 1, 4, 1, 5, 9};

  bool (*ascending)(int, int) = greaterThan;
  bool (*descending)(int, int) = lessThan;

  // perform sorting
  // bubbleSort(numbers, n, descending);
  // insertionSort(numbers, n, ascending);
  // selectionSort(numbers, n, descending);
  mergeSort(numbers, n);
  // print sorted array
  // for (int i = 0; i < n; i++)
  // printf("%d\n", numbers[i]);

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

void bubbleSort(int numbers[], int n, bool (*comparator)(int x, int y))
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i - 1; j++)
      if ((*comparator)(numbers[j], numbers[j + 1]))
        swap(&numbers[j], &numbers[j + 1], sizeof(int));
}

void insertionSort(int numbers[], int n, bool (*comparator)(int x, int y))
{
  for (int i = 0; i < n; i++)
  {
    int j;
    int insertee = numbers[i];

    for (j = i; j > 0 && !(*comparator)(insertee, numbers[j - 1]); j--)
      swap(&numbers[j - 1], &numbers[j], sizeof(int));

    numbers[j] = insertee;
  }
}

void selectionSort(int numbers[], int n, bool (*comparator)(int x, int y))
{
  for (int i = 0; i < n; i++)
  {
    int max_index = 0;

    for (int j = 1; j < n - i; j++)
      if ((*comparator)(numbers[j], numbers[max_index]))
        max_index = j;

    swap(&numbers[n - i - 1], &numbers[max_index], sizeof(int));
  }
}

void mergeSort(int numbers[], int n)
{
  if (n == 1)
    return;

  int former_n = n / 2;
  int latter_n = n - n / 2;

  int former_numbers[former_n];
  int latter_numbers[latter_n];

  memcpy(former_numbers, numbers, sizeof(int) * former_n);
  memcpy(latter_numbers, numbers + former_n, sizeof(int) * latter_n);

  mergeSort(former_numbers, former_n);
  mergeSort(latter_numbers, latter_n);

  // Todo: merge former and latter halves
}
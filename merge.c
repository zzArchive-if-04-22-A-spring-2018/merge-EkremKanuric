#include <stdio.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 64

void read_array(int* array, int n);
void merge(int* first_array, int n_first, int* last_array, int n_last, int* merged_array);
void print_array(int* array, int n);

int main(int argc, char* argv[])
{
  int test_case_count;
  scanf("%d", &test_case_count);
  for (int i = 0; i < test_case_count; i++) {
    int first_array[MAX_ARRAY_SIZE];
    int second_array[MAX_ARRAY_SIZE];
    int merged_array[MAX_ARRAY_SIZE];

    int n_first;
    scanf("%d", &n_first);
    read_array(first_array, n_first);

    int n_second;
    scanf("%d", &n_second);
    read_array(second_array, n_second);
    merge(first_array, n_first, second_array, n_second, merged_array);
    print_array(merged_array, n_first + n_second);
  }
}

void read_array(int* array, int n)
{
  for (int i = 0; i < n; i++) {
    scanf("%d", &(array[i]));
  }
}

void print_array(int* array, int n)
{
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void merge(int* first_array, int n_first, int* second_array, int n_second, int* merged_array)
{
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n_first && j < n_second)
  {
    if (first_array[i] < second_array[j])
      {
        merged_array[k] = first_array[i];
        i++;
       }
    else
      {
        merged_array[k] = second_array[j];
        j++;
      }
    k++;
  }
  while (n_first > i)
  {
    merged_array[k] = first_array[i];
    i++;
    k++;
  }
  while (n_second > j)
  {
    merged_array[k] = second_array[j];
    j++;
    k++;
  }
}

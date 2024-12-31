#include<stdio.h>
#include <stdlib.h>


void do_sort(int* arr, int size) {

}

int qsort_compare(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int* copy_array(int* arr, int size) {
  int* res = malloc(size * sizeof(int));
  for(int i = 0; i < size; i++) {
    res[i] = arr[i];
  }

  return res;
}

// if is sorted will return 0, otherwise pointer to sorted array.
int* is_sorted(int* arr, int size){
  int* copy = copy_array(arr, size);
  qsort(copy, size, sizeof(int), qsort_compare);

  for(int i = 0; i < size; i++) {
    if (arr[i] != copy[i]) return copy;
  }

  return 0;
}

void print(int* arr, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  int arr_size = 0;
  scanf("%i", &arr_size);
  printf("arr_size is %i\n", arr_size);
  int* arr = malloc(arr_size * sizeof(int));
  for(int i = 0; i < arr_size; i++) {
    int n = 0;
    scanf("%i", &n);
    arr[i] = n;
  }

  printf("Input:\t");
  print(arr, arr_size);

  printf("Output:\t");
  print(arr, arr_size);

  int* sorted = is_sorted(arr, arr_size);
  if (sorted) {
    printf("Sorted:\t");
    print(sorted, arr_size);
    return 1;
  }

  return 0;
}
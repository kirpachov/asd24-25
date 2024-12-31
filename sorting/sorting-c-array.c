#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
    Non funziona: la parte finale non scrive agli indici giusti :(

void brutto_merge_sort(int* punteggi, int start, int end){
  int size = end - start + 1;
  assert(size >= 0);
  if (size < 2) return;
  if (size == 2) {
    if (punteggi[start] > punteggi[end]) {
      int n = punteggi[end];
      punteggi[end] = punteggi[start];
      punteggi[start] = n;
    }

    return;
  }

  int middle = start + size / 2;
  brutto_merge_sort(punteggi, start, middle);
  brutto_merge_sort(punteggi, middle + 1, end);
  int* trash = malloc(size * sizeof(int));
  for(int i = 0; i < size; i++)
    trash[i] = punteggi[i + start];

  int left = 0;
  int right = middle + 1;
  while(left + right < size) {
    if (trash[left] > trash[right]) {
      punteggi[start + left] = trash[right];
      left++;
    } else {
      punteggi[start + right] = trash[left];
      right++;
    }
  }
}
*/


void brutto_merge_sort(int* punteggi, int start, int end){
  int size = end - start + 1;
  assert(size >= 0);
  if (size < 2) return;
  if (size == 2) {
    if (punteggi[start] > punteggi[end]) {
      int n = punteggi[end];
      punteggi[end] = punteggi[start];
      punteggi[start] = n;
    }

    return;
  }

  int middle = start + size / 2;
  brutto_merge_sort(punteggi, start, middle);
  brutto_merge_sort(punteggi, middle + 1, end);
  int* trash = malloc(size * sizeof(int));
  for(int i = 0; i < size; i++)
    trash[i] = punteggi[i + start];

  int left = 0, right = middle + 1, index = start;
  while(index < end) {
    if (trash[left] > trash[right]) {
      punteggi[index++] = trash[right];
      right++;
    } else {
      punteggi[index++] = trash[left];
      left++;
    }
  }
}

void do_sort(int* arr, int size) {
  brutto_merge_sort(arr, 0, size - 1);
}

// -----------------------------------------------------
// Don't edit below this line
// -----------------------------------------------------

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
int* sorted_copy(int* arr, int size){
  int* copy = copy_array(arr, size);
  assert(copy);
  qsort(copy, size, sizeof(int), qsort_compare);
  assert(copy);

  return copy;
}

void print(int* arr, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

bool arr_equal(int* arr1, int* arr2, int size) {
  assert(size >= 0);
  assert(arr1);
  assert(arr2);

  for(int i = 0; i < size; i++) {
    if (arr1[i] != arr2[i]) return 0;
  }

  return 1;
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

  int* sorted = sorted_copy(arr, arr_size);
  assert(sorted);
  assert(arr);

  printf("Input:\t");
  print(arr, arr_size);

  do_sort(arr, arr_size);

  printf("Output:\t");
  print(arr, arr_size);

  if (!(arr_equal(sorted, arr, arr_size))) {
    printf("Sorted:\t");
    print(sorted, arr_size);
    return 1;
  }

  printf("ok\n");

  return 0;
}
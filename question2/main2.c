#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int arr[] = {6, 57, 14, 21, 11, 3, 22, 42, 9, 15};
// int arr[] = {1, 3, 5, 9};
// int arr[] = {2, 4, 6, 8};
int n = sizeof arr / sizeof *arr;

void printArray(int* arr, int n);

int main() {
// Building odd and even arrays
   int i, j, k;
   int oddSize = 0, evenSize = 0;
   int* oddArray = NULL, *evenArray = NULL;

   for (i = 0; i < n; ++i)
      if (arr[i] % 2 == 0)
         ++evenSize;

   oddSize = n - evenSize;

   if (evenSize > 0) {
      evenArray = (int*)malloc(sizeof(int) * evenSize);
      assert(evenArray);
   }
   if (oddSize > 0) {
      oddArray = (int*)malloc(sizeof(int) * oddSize);
      assert(oddArray);
   }

   for (i = j = k = 0; i < n; ++i)
      if (arr[i] % 2 == 0)
         evenArray[j++] = arr[i];
      else
         oddArray[k++] = arr[i];

   printf("Original array : ");
   printArray(arr, n);

   printf("Even array : ");
   printArray(evenArray, evenSize);

   printf("Odd array : ");
   printArray(oddArray, oddSize);

   if (evenArray) {
      free(evenArray);
      evenArray = NULL;
   }
   if (oddArray) {
      free(oddArray);
      oddArray = NULL;
   }
   
   return 0;
}
void printArray(int* arr, int n) {
   if (n == 0) {
      printf("[ ]\n");
      return;
   }
   
   int i;
   printf("[ ");

   for (i = 0; i < n; ++i)
      printf("%d, ", arr[i]);

   printf("\b\b ]\n");
}
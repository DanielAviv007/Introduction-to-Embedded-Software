#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int arr[] = {50, 60, 60, 72, 81, 81, 81, 81, 93, 93};
int n = sizeof arr / sizeof *arr;

void printArray(int* arr, int n);

int main() {
// Building new array from arr without duplicates
   int i, j;
   int uniqueSize = 1;
   int* uniqueArray = NULL;

   for (i = 0; i < n - 1; ++i)
      if (arr[i] != arr[i + 1])
         ++uniqueSize;

   uniqueArray = (int*)malloc(sizeof(int) * uniqueSize);
   assert(uniqueArray);

   uniqueArray[uniqueSize - 1] = arr[n - 1];

   for (i = j = 0; i < n - 1; ++i)
      if (arr[i] != arr[i + 1])
         uniqueArray[j++] = arr[i];

   printf("Original Array : ");
   printArray(arr, n);

   printf("Unique Array : ");
   printArray(uniqueArray, uniqueSize);
      
   free(uniqueArray);
   uniqueArray = NULL;
   
   return 0;
}
void printArray(int* arr, int n) {
   int i;
   printf("[ ");

   for (i = 0; i < n; ++i)
      printf("%d, ", arr[i]);

   printf("\b\b ]\n");
}
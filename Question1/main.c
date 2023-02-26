#include <stdio.h>

// Functions
int calculator(int num1, int num2, char op);
int reversedNumber(unsigned number);

double square(double num);
double cube(double num);
double power(double num, unsigned pwr);

int isEven(int num);
int isOdd(int num);

// Pointers
void inputArray(int* arr, int n);
void printArray(int* arr, int n);

int hasElementEqualsNeighboursSum(int* arr, int n);

void reverseArray(int* arr, int n);
int main() {
   // int res1 = calculator(35, 7, '/');
   // int res2 = calculator(17, 0, '/');
   // int res3 = calculator(99, 3, '$');

   // printf("res1 : %d, res2 : %d, res3 : %d\n", res1, res2, res3);

   // int number1 = 5614;
   // int number2 = 320;

   // printf("reversed number of %d is %d\n", number1, reversedNumber(number1));
   // printf("reversed number of %d is %d\n", number2, reversedNumber(number2));

   // double num = 0.5;

   // printf("%.2lf ^ 2 = %.2lf\n", num, square(num));
   // printf("%.2lf ^ 3 = %.2lf\n", num, cube(num));
   // printf("%.2lf ^ 4 = %.2lf\n", num, power(num, 4));

   // int num1 = 13;
   // int num2 = 100;

   // printf("is %d even? %d, is %d odd? %d\n", num1, isEven(num1), num1, isOdd(num1));
   // printf("is %d even? %d, is %d odd? %d\n", num2, isEven(num2), num2, isOdd(num2));

   // int arr[5];
   // int n = sizeof arr / sizeof *arr;

   // inputArray(arr, n);
   // printArray(arr, n);

   // int arr1[] = {1, 2, 7, 5, 9, 6};
   // int arr2[] = {1, 2, 8, 5, 9, 6};
   // int n1 = sizeof arr1 / sizeof *arr1;
   // int n2 = sizeof arr2 / sizeof *arr2;

   // printArray(arr1, n1);
   // printf("Has an element that equals to the sum of it's neighbours ? %d\n", hasElementEqualsNeighboursSum(arr1, n1));
   
   // printArray(arr2, n2);
   // printf("Has an element that equals to the sum of it's neighbours ? %d\n", hasElementEqualsNeighboursSum(arr2, n2));

   // int arr[] = {1, 3, 2, 5, 6};
   // int n = sizeof arr / sizeof *arr;

   // printf("Before : ");
   // printArray(arr, n);

   // reverseArray(arr, n);
   
   // printf("After reversing the array : ");
   // printArray(arr, n);

   return 0;
}

int calculator(int num1, int num2, char op) {
   int res = 0;

   switch (op) {
   case '+':
      res = num1 + num2;
      break;
   case '-':
      res = num1 - num2;
      break;
   case '*':
      res = num1 * num2;
      break;
   case '/':
      if (num2 != 0)
         res = num1 / num2;
      else
         printf("Can't divide by zero\n");
      break;
   case '%':
      if (num2 != 0)
         res = num1 % num2;
      else
         printf("Can't mod by zero\n");
      break;
   default:
      printf("Invalid operator\n");
   }

   return res;
}

int reversedNumber(unsigned number) {
   unsigned rev = 0;

   while (number > 0) {
      rev = rev * 10 + number % 10;

      number /= 10;
   }   

   return rev;
}

double square(double num) {
   return num * num;   
}

double cube(double num) {
   return square(num) * num;
}

double power(double num, unsigned pwr) {
   int i;
   double res = 1.0;

   for (i = 0; i < pwr; ++i)
      res *= num;

   return res;
}

int isEven(int num) {
   return num % 2 == 0;
}

int isOdd(int num) {
   return !isEven(num);
}

void inputArray(int* arr, int n) {
   int i;

   for (i = 0; i < n; ++i) {
      printf("arr[%d] : ", i);
      scanf("%d", arr + i);
   }
}

void printArray(int *arr, int n) {
   int i;

   printf("[ ");

   for (i = 0; i < n; ++i)
      printf("%d, ", arr[i]);
   
   printf("\b\b ]\n");
}

int hasElementEqualsNeighboursSum(int *arr, int n) {
   int i;

   for (i = 1; i < n - 1; ++i)
      if (arr[i] == arr[i - 1] + arr[i + 1])
         return 1;

   return 0;
}

void reverseArray(int* arr, int n) {
   int i = 0, j = n - 1;
   int tmp;

   while (i < j) {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;

      ++i;
      --j;
   }
}
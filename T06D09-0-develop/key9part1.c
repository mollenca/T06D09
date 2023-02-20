#include <stdio.h>
 #define Size 10
 int input(int *buffer, int *length);
 void output(int *buffer, int length);
 int sum_numbers(int *buffer, int length);
 int find_numbers(int *buffer, int length, int number, int *numbers);

 int main() {
   int mas[Size];
   int numbers[Size];
   int length;
   if (input(mas, &length)) {
     int sum = sum_numbers(mas, length);
     int num_length = find_numbers(mas, length, sum, numbers);
     printf("%d\n", sum);
     output(numbers, num_length);
   }
 }
 int input(int *buffer, int *length) {
   char c = 0;
   int check = 1;
   if (scanf("%d%c", length, &c) && c == '\n' && *length >= 0 &&
       *length <= Size) {
     for (int *p = buffer; p - buffer < *length; p++)
       if (scanf("%d%c", p, &c) && (c == ' ' || c == '\n' || c == EOF)) {
         continue;
       } else {
         printf("n/a\n");
         check = 0;
       }
   } else {
     printf("n/a\n");
     check = 0;
   }
   return check;
 }
 void output(int *buffer, int length) {
   for (int *p = buffer; p - buffer < length - 1; p++) printf("%d ", *p);
   printf("%d\n", *(buffer + length - 1));
 }

 int sum_numbers(int *buffer, int length) {
   int sum = 0;
   for (int i = 1; i < length; i++)
     if (*(buffer + i) % 2 == 0) sum = sum + *(buffer + i);
   return sum;
 }
 int find_numbers(int *buffer, int length, int number, int *numbers) {
   int num_length = 0;
   for (int i = 0; i < length; i++)
     if (*(buffer + i) != 0 && number % *(buffer + i) == 0) {
       *(numbers + num_length) = *(buffer + i);
       num_length++;
     }
   return num_length;
 }

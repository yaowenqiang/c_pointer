/*
 * decimal_to_binary.c - Accept a decimal number and convert to binary ,
 * and count the number of 1s in the binary number
 */

#include <stdio.h>

int main()
{
   long num, decimal_num, remainder , base = 1, binary = 0, number_of_ones = 0;
   printf("Enter a decimal integer \n");
   scanf("%ld", &num);
   decimal_num = num;
   while(num > 0) {
      remainder = num % 2;
      /* to count num of 1s */

      if (remainder == 1) {
          number_of_ones += 1; 
      }
      binary = binary + remainder * base;
      num = num / 2;
      base = base * 10;
   }
      printf("Input number is %ld\n", decimal_num);
      printf("Its binary equivalent is %ld\n", binary);
      printf("Number of ones in the binary  is %ld", number_of_ones);
}

#include<stdio.h>
#include<math.h>

int main()
{
    int number, originalNumer, reminder, result = 0,n = 0;
    printf("Enter an ingeter: ");
    scanf("%d", &number);
    originalNumer = number;

    while(originalNumer > 0 ) {
        originalNumer /= 10;
        ++n;

    }
    originalNumer = number;

    while(originalNumer > 0 ) {
        reminder = originalNumer % 10;
        result += pow(reminder, n);
        originalNumer /= 10;
    }


    if (result == number ) {
        printf("%d is an Armstrong number.\n",number);
    } else {
        printf("%d is not an Armstrong number.\n",number);

    }

}

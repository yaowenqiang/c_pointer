#include<stdio.h>
#include<math.h>

int main()
{
    long long int number, originalNumer, reminder, result = 0,n = 0;
    printf("Enter an ingeter: ");
    scanf("%lld", &number);
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
        printf("%lld is an Armstrong number.\n",number);
    } else {
        printf("%lld is not an Armstrong number.\n",number);

    }

}

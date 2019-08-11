/*
 * funds1.c - 把结构体成员作为参数传递
 */

#include <stdio.h>
#define FUNDLEN 50
struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savedfund;
};


double sum(double, double);
double sum2(const struct funds *);
double sum3(const struct funds);
int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Locky's Savings and Loan",
        8543.94
    };
    printf("Stan has a total of $%.2f.\n",sum(stan.bankfund, stan.savedfund));
    printf("Stan has a total of $%.2f.\n",sum2(&stan));
    printf("Stan has a total of $%.2f.\n",sum3(stan));
    return 0;
}

double sum(double x, double y) 
{
    return x + y;
}

double sum2(const struct funds * money) 
{
    return money->bankfund + money->savedfund;
}

double sum3(const struct funds  moolah) 
{
    return moolah.bankfund + moolah.savedfund;
}

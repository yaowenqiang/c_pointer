/*
 * pizza.c 
 */

#include <stdio.h>

#define PI 3.14159

int main(void)
{
    float area, circum, radius;
    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;

    printf("Your basic pizza parameters are as folllows:\n") ;
    printf("circumferences  =%1.2f, area = %1.2f\n", circum, area);
    printf("circumferences  =%.2f, area = %.2f\n", circum, area);
    printf("circumferences  =%f, area = %f\n", circum, area);
    return 0;
}

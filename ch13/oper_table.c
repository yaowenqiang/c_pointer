#include <stdio.h>

double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);

double (*oper_func[]) (double, double) = {
    add, sub, mul, div
};
int main(void)
{
    
    double a = 1.0, b = 2.0;
    int oper = 0;
    double result = oper_func[oper](a,b);
    printf("%f\n", result);
    return 0;
}


double add(double op1, double op2) {
    return  op1 + op2;
}
double sub(double op1, double op2) {
    return  op1 - op2;
}
double mul(double op1, double op2) {
    return  op1 * op2;
}
double div(double op1, double op2) {
    return  op1 / op2;
}

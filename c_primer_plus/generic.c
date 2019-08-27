/*
 * generic c  -- 定义泛类型
 */

#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG (180/(4*atan(1)))

//泛开支平方根函数

#define SQRT(X) _Generic((x), \
    long double: sqrtl, \
    default : sqrt, \
float: sqrtf)(X)


#define SIN(X) _Generic((X),\
    long double: sinl((1) / RAD_TO_DEG), \
    default: sin((X) / RAD_TO_DEG), \
    float: sinf((X) / RAD_TO_DEG) \
)


int main(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;

    float y = SQRT(x);
    double yy = SQRT(xx);
    long double yyy = SQRT(xxx);

    printf("%.17lf\n", y);     // 匹配 float
    printf("%.17lf\n", yy);    // 匹配 default
    printf("%.17Lf\n", yyy);   // 匹配 long double


    int i = 45;
    yy = SQRT(i);        //匹配 default

    printf("%.17lf\n", yy);

    yyy = SIN(xxx);
    printf("%.17Lf\n", yyy);  //工本long double


    return 0;
}

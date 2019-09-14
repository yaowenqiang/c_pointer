#include <stdio.h>
#define N_VALUES 5
int main(void)
{
    
    float values[N_VALUES];
    float *vp;
    for (vp = &values[0]; vp < &values[N_VALUES]; ) {
        *vp ++ = 0; 
    }
    float *vp2 = &values[2];
    float *vp4 = &values[4];
    printf("%ld\n", vp4 - vp2);
    
    return 0;
}

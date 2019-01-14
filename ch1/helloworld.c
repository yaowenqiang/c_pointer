#include <stdio.h>

void main(int argc, char const *argv[])
{
    printf( "Hello world!");
    int i;
    int input[100];
    for(i=0;i < 10;i++){
        printf("%d",i);
    }
    for(i=0;i<100;i++) {
        scanf("%d", &input[i]);
        printf("please inter a number!\n");
    }
    
}

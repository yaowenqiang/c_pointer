/*
** Mystery function
**
**	The argument is a value in the range 0 through 100.
*/
#include <stdlib.h>
#include <stdio.h>
void mystery(int n);

void mystery( int n )
{
	n += 5;
	n /= 10;
    printf("aaa");
	//printf("%s\n", "**********" + 10 - n );
	printf("%s\n", "**********" );
}

int main(void)
{
    mystery(1);
    return 0;
}

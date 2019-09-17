/*
 * 处理命令行参数　
 */

#include <stdio.h>

#define TRUE 1

void process_standdard_input(void);

void process_file(char * file_name);

int option_a, option_b; /* etc. */;

int main(int argc, char **argv)
{
    while(*++argv != NULL && **argv != '-')
    {
	    switch(*++*argv) {
		    case 'a':
			    option_b = TRUE;
			    break;
		    case 'b':
			    option_b = TRUE;
			    break;
		    /* etc. */
	    }
    }

    if (*argv == NULL ) {
	    process_standdard_input();
    } else {
	    do {
		    process_file(*argv);
	    } while (*++argv != NULL);
    }
    return 1;
}

void process_standdard_input (void) 
{
   printf("process standard input"); 
}

void process_file(char * file_name)
{
    printf("process file: %s\n", file_name);
}


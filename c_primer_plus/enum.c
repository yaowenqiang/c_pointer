/*
 * enum c - 傅枚举类型的值
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char * s_gets(char * st, int n);

enum spectrum{red, orange, yellow, green, blue, violet};
//enum custom_color{orange,red, green,yellow,violet,blue};
const char * colors[] = {"red","orange", "Yellow", "Green", "blue", "violet"};

#define LEN 30

int main(void)
{
    printf("%d\n", red);
    printf("%d\n", orange);
    printf("%d\n", yellow);
    printf("%d\n", green);
    printf("%d\n", blue);
    printf("%d\n", violet);
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;

    puts("Enter a color ( empty line to quit):");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0') {
        for (color = 0; color < violet; color++) {
            if (strcmp(choice, colors[color]) == 0) {
                color_is_found = true;
                break;
            } 
        }

        if (color_is_found) {
            switch (color) {
                case red:
                    puts("Roses are red");
                    break;
                case orange:
                    puts("Poppies  are orange");
                    break;
                case yellow:
                    puts("Sunflowers are yellow");
                    break;
                case green:
                    puts("Grass are green");
                    break;
                case blue:
                    puts("bluebells are red");
                    break;
                case violet:
                    puts("Violets are red");
                    break;
            }
        } else {
            printf("I don't know about the color %s.\n", choice);
        }
        color_is_found = false;
        puts("next color, please (empty line to quit):");
    }

    puts("GoodBye!");
    return 0;
}

char * s_gets(char * st ,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n ,stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}

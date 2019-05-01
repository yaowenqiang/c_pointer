#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[argc+1]) {
    puts("Hello_World!");
    if (argc > 1) {
        while (true) {
            puts("some programs nerver stop");
        }
    } else {
        do {
            puts("but this one does");
        } while (0);
    }
    return EXIT_SUCCESS;
}


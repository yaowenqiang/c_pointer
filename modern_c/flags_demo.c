/*
 * falgs.c 
 * https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
 */

#include <stdio.h>
#include <stdlib.h>


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

enum corvid { magpie , raven , jay , chough , corvid_num , };
#define FLOCK_MAGPIE 1U 
#define FLOCK_RAVEN 2U 
#define FLOCK_JAY 4U 
#define FLOCK_CHOUGH 8U 
#define FLOCK_EMPTY 0U 
#define FLOCK_FULL 15U

int main(void)
{
    unsigned flock = FLOCK_EMPTY;
    unsigned flock_magpie = FLOCK_MAGPIE;
    unsigned flock_raven = FLOCK_RAVEN;
    unsigned flock_jay = FLOCK_JAY;
    unsigned flock_chough = FLOCK_CHOUGH;
    unsigned flock_full = FLOCK_FULL;
    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flock));
    printf("\n");
    printf("%d\n", flock);
    printf("%d\n", flock_magpie);
    printf("\n");
    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flock_magpie));
    printf("\n");
    printf("%d\n", flock_raven);
    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flock_raven));
    printf("\n");
    printf("%d\n", flock_jay);
    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flock_jay));
    printf("\n");
    printf("%d\n", flock_chough);
    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flock_chough));
    printf("\n");
    printf("%d\n", flock_full);
    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flock_full));
    printf("\n");

    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(flock & flock_full));
    printf("\n");


}


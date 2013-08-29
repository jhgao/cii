#include "atom.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "def.h"

void rand_str(char *dest, size_t length) {
        char charset[] = "0123456789"
                "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        while (length-- > 0) {
                size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
                *dest++ = charset[index];
        }
        *dest = '\0';
}

int main(int argc, char * argv[])
{
        int i = STRNUM;
        char str[STRLENMAX];
        size_t len;
        char *atom;

        int hit = 0;
        int miss = 0;

        srand(time(NULL));

        while( i-- > 0 ){
                len = (double) rand() / RAND_MAX * STRLENMAX - 1;
                rand_str(str, len);
                atom = (char *)Atom_string(str);
                if (Atom_length(atom) == len)
                        hit ++;
                else
                        miss ++;
        }

        printf("hit %d / miss %d \n", hit, miss);

        return 0;
}

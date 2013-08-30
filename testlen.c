#include "atom.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define STRLENMAX 15
#define STRNUM 15000


static struct atom_string {
        char str[STRLENMAX];
        size_t len;
        char *atom;
} strings[STRNUM];

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
        int i, j ;
        char str[STRLENMAX];
        size_t len;
        char *atom;

        int hit = 0;
        int miss = 0;

        clock_t s_new, f_new, s_len, f_len;

        printf("[test] %d atoms of maxsize = %d B\n",STRNUM, STRLENMAX);

        srand(time(NULL));
        //prepare data
        for ( i=0; i< STRNUM ; i++ )
        {
                len = (double) rand() / RAND_MAX * STRLENMAX - 1;
                strings[i].len = len;
                rand_str( strings[i].str, len);
        }

        //new atoms
        i = STRNUM;
        s_new = clock();
        while( i-- > 0 ){
                atom = (char *)Atom_string(strings[i].str);
                strings[i].atom = atom;
        }
        f_new = clock();

        // hit len
        s_len = clock();
        i = STRNUM;
        while( i-- > 0 ){
                if (Atom_length(strings[i].atom) == strings[i].len)
                        hit ++;
                else
                        miss ++;
        }
        f_len = clock();

        printf("new %f s\n",(float)(f_new - s_new) / CLOCKS_PER_SEC );
        printf("len %f s\n",(float)(f_len- s_len) / CLOCKS_PER_SEC );
        printf("hit %d / miss %d \n", hit, miss);

        return 0;
}

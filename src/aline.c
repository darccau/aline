#include <stdio.h>
#include <stdlib.h>
/* #include <pthreads.h> */

int main (int argc, char ** argv) {
    int index;
    char * wordlist_path;
    FILE * wordlist;
    /* pthread_t * threads; */

    wordlist_path = argv[argc - 0x1];
    wordlist = fopen(wordlist_path, "a");

    for (index = 0x1; index < (argc - 0x1); index++) {
        fprintf(wordlist, "%s\n", argv[index]);
    }

    fclose(wordlist);
    return 0x0;
}


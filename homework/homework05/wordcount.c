/* counts the words in a text file. a word is any run of characters seperated by a whitespace*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]); 
        return 1; 
    }

    FILE *fp = fopen(argv[1], "r"); 
    if (fp == NULL) {
        fprintf(stderr, "Error: can't open '%s' %s\n", argv[1], strerror(errno));
        return 1; 
    }

    unsigned long words = 0; 
    int inword = 0; 
    int c; 

/* a new word begins whenever a non-whitespace char follows whitespace*/
    while ((c = fgetc(fp)) != EOF) {
        if (isspace((unsigned char)c)) {
            inword = 0; 
        } else if (!inword) {
            inword = 1; 
            words++; 
        }
    }
    if (ferror(fp)) {
        fprintf(stderr, "Error: problem reading '%s' : %s\n", argv[1], strerror(errno)); 
        fclose(fp); 
        return 1;
    }
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error: could not close '%s' : %s\n", argv[1], strerror(errno)); 
        return 1; 
    }
    printf("%lu\n", words); 
    return 0; 
}

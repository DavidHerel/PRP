#include <stdio.h>

int main(int argv, char *argc[]){
    char *fname;
    FILE *f;
    fname = argc[1];
    
    if ((f = fopen(fname, "w")) == NULL){
        fprintf(stderr, "Error in opening file \n");
        return 100;
    }    
    
    fprintf(f, "Ahoj kamarade\n");
    
    if (fclose(f)==EOF){
        fprintf(stderr, "Error in closing file\n");
        return 101;
    }
}

#include <stdio.h>
/*
    File testing - different types of this problem
    1) Trying to do something with files xD
*/

int main(int argc, char *argv[]){
    
    FILE *f;
    char *fname;
    
    //checking file
    if (argc > 1){
        fname = argv[1];
    } else{
        fname = "a.out";
    }
    
    //opening file
    if ((f = fopen(fname, "w")) == NULL){
        fprintf(stderr, "Error in opening file %s", fname);
        return 100;
    }
    
    fprintf(f, "You gave me %d arguments.\n", argc);
    for (int i = 0; i < argc; i++){
        fprintf(f, "%d argument was: %s \n", i, argv[i]);
    }
    
    //closing file
    if (fclose(f) == EOF){
        fprintf(stderr, "Error in closing %s", fname);
        return 101;
    }
    return 0;

}

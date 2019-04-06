#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    int size;
    srand(time(NULL));
    printf("20000\n");
    //printf("%d\n", rand());
    
    size = rand() / 2;
    size = (size > 1000 ? 1000 : size);
    for (int i = 0;i < size; ++i){
        int rnd = rand();
        if (rnd < RAND_MAX / 3){
            printf("a %d\n", rand());
        }else if (rnd < RAND_MAX /3 * 2) {
            printf("r\n");
        }else{
            printf("g %d\n", rand());
        }
        
    }    
}

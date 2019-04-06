#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define IMAGE_COMMENT "Zkouska"
#define WIDTH 640
#define HEIGHT 480
#define MAX_COLOR_VALUE 250

void red(const char *fname){
    FILE *f;
    
    if ((f = fopen(fname, "wb")) == NULL){
        fprintf(stderr, "Error in opening %s \n", fname);
    }
    fprintf(f, "P6\n %s\n %d\n %d\n %d\n", IMAGE_COMMENT, WIDTH, HEIGHT, MAX_COLOR_VALUE);
    char color[3] = {255, 0, 0};
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            assert((fwrite(color, 1, 3, f))==3);
        }
    }
    if (fclose(f) == EOF){
        fprintf(stderr,"Error in closing %s", fname);
    }
}

int main(int argv, char *argc[]){
    red(argc[1]);
    return 0;


}

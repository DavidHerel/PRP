#include <png.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "exam.h"

typedef struct{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} rect_t;
    
void fill_image (bitmap_t *im, pixel_t c){
    for (int x = 0; x < im->width; x++){
        for (int y = 0; y < im->height; y ++){
            pixel_t *pixel = pixel_at(im, x, y);
            pixel->red = 255;
            pixel->green = 0;
            pixel->blue = 0;
        }
    }
}

void draw_rectangle (bitmap_t * im, rect_t r){
    int xfrom = (im->width/2) - ((im->width/2)/2);
    int xto = (im->width/2) + ((im->width/2)/2);
    int yfrom = (im->height/2) - ((im->height/2)/2);
    int yto = (im->height/2) + ((im->height/2)/2);
    for (int x = xfrom; x < xto; x++){
        for (int y = yfrom; y < yto; y++){
            pixel_t *pixel = pixel_at(im, x, y);
            pixel->red = 0;
            pixel->green = 255;
            pixel->blue = 0;
        }
    }

}

void draw_data (bitmap_t * im, void * data);

int main (int argv, char *argc[]){

    for (int i = 0; i < argc; i++){
        if (argv[i] != '-s'){
            fpritnf(stderr, "You didnt give us size, so We will use 100x100\n");
        } else if(argv[i] != '-o1'){
            fprintf(stderr,"You didnt give us name of file \n");
            return 101;
        } else if (argv[i] != '-b1'){
            fprintf(stderr, "You didnt give us colour, we will use red\n");
        } else if (argv[i] != '-f1'){
            fprintf(stderr, "You didnt give us colour of rectangle, we will use green\n");           
        }
    }

    bitmap_t im;
    char filename[] = "image.png"; 

    im.width = 100;
    im.height = 100;
    
    im.pixels = calloc (im.width * im.height, sizeof (pixel_t));

    if (!im.pixels) {
	    return -1;
    }
    
    pixel_t pixel;  
    fill_image(&im, pixel);  
    rect_t rect;   
    draw_rectangle(&im, rect);
    save_png_to_file (&im, filename);

    free (im.pixels);

    return 0;
}

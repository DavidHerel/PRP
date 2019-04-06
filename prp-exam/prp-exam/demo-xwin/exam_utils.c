/*
 * File name: exam_utils.c
 * Date:      2017/01/16 17:00
 * Author:    Jan Faigl
 */

#include <stdio.h>
#include <assert.h>

#include "exam_utils.h"

#define IMAGE_COMMENT "#PR2-exam"

#define MAX_COLOR_VALUE 255

void save_image_red(int w, int h, const char *fname) 
{
   FILE *fd = fopen(fname, "wb");
   assert(fd != NULL);
   fprintf(fd, "P6\n %s\n %d\n %d\n %d\n", IMAGE_COMMENT, w, h, MAX_COLOR_VALUE);
   unsigned char color[3] = {255, 0, 0}; /* R G B */
   for(int y = 0; y < h; ++y) {
      for(int x = 0; x < w; ++x) {
         assert(fwrite(color, 1, 3, fd) == 3);
      }
   }
   fclose(fd);
}

void save_image_green(int w, int h, const char *fname) 
{
   FILE *fd = fopen(fname, "wb");
   assert(fd != NULL);
   fprintf(fd, "P6\n %s\n %d\n %d\n %d\n", IMAGE_COMMENT, w, h, MAX_COLOR_VALUE);
   unsigned char color[3] = {0, 255, 0}; /* R G B */
   for(int y = 0; y < h; ++y) {
      for(int x = 0; x < w; ++x) {
         assert(fwrite(color, 1, 3, fd) == 3);
      }
   }
   fclose(fd);
}

void save_binary(int w, int h, int threshold, int* grid, const char *fname)
{
   FILE *fd = fopen(fname, "wb");
   assert(fd != NULL);
   fprintf(fd, "P6\n %s\n %d\n %d\n %d\n", IMAGE_COMMENT, w, h, MAX_COLOR_VALUE);
   unsigned char colors[2][3] = { {0, 0, 0}, {255, 255, 255} }; 
   for(int y = 0; y < h; ++y) {
      for(int x = 0; x < w; ++x) {
         assert(fwrite(colors[*(grid++) < threshold ? 0 : 1], 1, 3, fd) == 3);
      }
   }
   fclose(fd);
}

void save_image_rgb(int w, int h, unsigned char *img, const char *fname)
{
   FILE *fd = fopen(fname, "wb");
   assert(fd != NULL);
   fprintf(fd, "P6\n %s\n %d\n %d\n %d\n", IMAGE_COMMENT, w, h, MAX_COLOR_VALUE);
   assert(fwrite(img, 1, w*h*3, fd) == w*h*3);
   fclose(fd);
}

/* end of exam_utils.c */

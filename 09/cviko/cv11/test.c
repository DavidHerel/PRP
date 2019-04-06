#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

void writeTest(const test_t *t, FILE *fout)
{
    //fwrite(&t->ival, sizeof(t->ival), 1, fout);
    //fwrite(&t->cval, sizeof(t->cval), 1, fout);
    fwrite(t, sizeof(*t), 1, fout);
}

void readTest(test_t *t, FILE *fout)
{
    //fread(&t->ival, sizeof(t->ival), 1, fout);
    //fread(&t->cval, sizeof(t->cval), 1, fout);
    fread(t, sizeof(*t), 1, fout);
}

void writeTest2(const test2_t *t, FILE *fout)
{
    int len = strlen(t->str);
    fwrite(&t->ival, sizeof(t->ival), 1, fout);
    fwrite(&t->cval, sizeof(t->cval), 1, fout);
    fwrite(&len, sizeof(len), 1, fout);
    fwrite(t->str, sizeof(char) * len, 1, fout);
}

void readTest2(test2_t *t, FILE *fout)
{
    int len;

    fread(&t->ival, sizeof(t->ival), 1, fout);
    fread(&t->cval, sizeof(t->cval), 1, fout);
    fread(&len, sizeof(len), 1, fout);
    t->str = malloc(sizeof(char) * (len + 1));
    fread(t->str, sizeof(char) * len, 1, fout);
    t->str[len] = 0;
}

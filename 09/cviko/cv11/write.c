#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int main(int argc, char *argv[])
{
    test_t *t = NULL;
    int t_alloc = 0;
    int t_size = 0;
    int ival, cval;

    while (scanf("%d %d", &ival, &cval) == 2){
        if (t_size == t_alloc){
            if (t_alloc == 0)
                t_alloc = 1;
            t_alloc *= 2;
            t = realloc(t, sizeof(*t) * t_alloc);
        }
        t[t_size].ival = ival;
        t[t_size].cval = cval;
        ++t_size;
    }

    fwrite(&t_size, sizeof(t_size), 1, stdout);
    for (int i = 0; i < t_size; ++i)
        writeTest(t + i, stdout);

    if (t != NULL)
        free(t);

    return 0;
}

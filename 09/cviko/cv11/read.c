#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int main(int argc, char *argv[])
{
    test_t *t = NULL;
    int t_size = 0;

    fread(&t_size, sizeof(t_size), 1, stdin);
    t = malloc(sizeof(*t) * t_size);

    for (int i = 0; i < t_size; ++i)
        readTest(t + i, stdin);

    for (int i = 0; i < t_size; ++i)
        printf("%d %d\n", t[i].ival, t[i].cval);

    if (t != NULL)
        free(t);

    return 0;
}

#ifndef __TEST_H__
#define __TEST_H__

struct test {
    int ival;
    char cval;
} __attribute__((packed));
typedef struct test test_t;

void writeTest(const test_t *t, FILE *fout);
void readTest(test_t *t, FILE *fout);

struct test2 {
    int ival;
    char cval;
    char *str;
};
typedef struct test2 test2_t;

void writeTest2(const test2_t *t, FILE *fout);
void readTest2(test2_t *t, FILE *fout);

#endif /* __TEST_H__ */

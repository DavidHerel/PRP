#include <stdio.h>

void increment(int* a){
    *a = *a + 1;
}
int main(void){
    int a = 10;
    increment(&a);
    printf("The value of a is %d\n", a);
    increment(&a);
    printf("The value of a is %d\n", a);

}

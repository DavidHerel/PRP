#include <stdio.h>
#include <string.h>
/*
typedef struct{
        char name[15];
        int age;

        
        } student;
        
void display(char [], int);
void show(student);

        
        
int main(int *argc, char *argv[]){
     student david;
     strcpy(david.name, "David");
     david.age = 20;
     display(david.name, david.age);
     show(david);
}

void display(char n[], int r){
    printf("In display function\n");
    printf("%s \t %d\n", n, r);
    
}

void show(student s){
    printf("\nIn show function\n");
    printf("%s \t %d\n", s.name, s.age);
    
}


typedef struct{
    char name[20];
    int age;
        } student;
        
int main(int *argc, char *argv[]){
    student david = {"David", 20};
    student *ptr;
    
    ptr = &david;

    printf("%s\t%d\n", david.name, david.age);
    printf("%s\t%d\n", ptr->name, ptr->age);
}
*/

typedef struct{
    char name[20];
    int age;
    } student;
    
void display(student *ptr);

int main(int *argc, char *argv[]){
    student david = {"David", 20};
    display(&david);    

}    

void display(student *ptr){
    printf("%s\t%d\n", ptr->name, ptr->age);
}


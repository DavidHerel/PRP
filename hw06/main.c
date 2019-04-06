#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int size = 0;

    int* all_matrix;
    char* all_oper;
    all_matrix = malloc(sizeof(int));
    all_oper = malloc(sizeof(char));
    int x=0;
    
    while (1){
        size = size + 1;
        all_matrix = realloc(all_matrix, size); 
        all_oper = realloc(all_oper, size);
        int n;
        int m;
         
        char operation;
        scanf("%d", &n);
        scanf("%d", &m);
        int matrix1[n][m];
         
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if ((scanf("%d", &x))==1){
                    matrix1[i][j] = x;
                } else{
                    fprintf(stderr, "Error: Chybny vstup!\n");
                    return 100;
                }
                     
                 
            }
        }
        
        for (int i = 0; i < size; i++){
            all_matrix[size-1] = matrix1[n][m];
            printf("%d", all_matrix[size-1]);
        }
        
         
         
        if ((operation = getchar())!= EOF){
            if((operation = getchar())!=EOF){     
                all_oper[size-1] = operation;
            }else {
                break;
            }
        } else{
            break;
        }   
        for (int i = 0; i < size; i++){
            printf("%d", all_matrix[size-i]);
        }
       
    } 
     
    
     
 
}

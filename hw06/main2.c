#include <stdio.h>
#include <stdlib.h>

void plus(int n, int m, int* matrix1[n][m], int* matrix2[n][m]){
    int final[n][m];
    int result;
    int lines = 0;
    int spaces = 0;
    
    for (int i = 0; i < n; i++){
        for (int j=0; j< m; j++){
            result = *matrix1[i][j] + *matrix2[i][j];
            *final[i][j] = result;       
        }
    }

    
    
    

}

void minus (int n, int m, int* matrix1[n][m], int* matrix2[n][m]){
    int final[n][m];
    int result;
    int lines = 0;
    int spaces = 0;
    
    for (int i = 0; i < n; i++){
        for (int j=0; j< m; j++){
            result = *matrix1[i][j] - *matrix2[i][j];
            *final[i][j] = result;       
        }
    }

    
}

void multiply(int n, int m, int r, int c, int* matrix1[n][m], int* matrix2[r][c]){
    int result = 0;
    int final[n][c];
    int lines = 0;
    int spaces = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < c; j++){
            for (int k = 0; k < r; k++){
                result = (*matrix1[i][k] * *matrix2[k][j]) + result;
            }
            *final[i][j] = result;
            result = 0;
        }
    }

   
}



int main(void){
   
    int n;
    int m;
    int x;
    
    char operation;
    
    int r;
    int c;
    int y;
    
    scanf("%d", &n);
    scanf("%d", &m);
    int matrix1[n][m];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if((scanf("%d", &x)==1)){
                matrix1[i][j] = x;
            }
            else{
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }   
        }
    }
    
    operation = getchar();
    if (operation == '\n'){
        operation = getchar();
    }
    
    scanf("%d", &r);
    scanf("%d", &c);
    
    int matrix2[r][c];
    
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &y);
            matrix2[i][j] = y;
        }
    }
    
    if (operation == '+'){
        if (n == r && m == c){
            int final[n][m];
            int result;
            int lines = 0;
            int spaces = 0;
            
            plus(n, m, matrix1, matrix2);
            
            printf("%d %d\n", n, m);
            for (int i = 0; i < n; i++){
                for (int j=0; j< m; j++){
                    if (lines != m && lines >0){
                        printf(" %d", final[i][j]);
                        lines = lines + 1;
                    }
                    if (lines == 0){
                        printf("%d", final[i][j]);
                        lines = lines + 1;
                    }
                    spaces = spaces + 1;
                    if (spaces == m){
                        printf("\n");
                        spaces = 0;
                        lines = 0;
                    }      
                }
            }

        
        } else{
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
    }
    
    if (operation == '-'){
        if (n == r && m == c){
            int final[n][m];
            int result;
            int lines = 0;
            int spaces = 0;
            
            minus(n, m, matrix1, matrix2);
            
            printf("%d %d\n", n, m);
            for (int i = 0; i < n; i++){
                for (int j=0; j< m; j++){
                    if (lines != m && lines >0){
                        printf(" %d", final[i][j]);
                        lines = lines + 1;
                    }
                    if (lines == 0){
                        printf("%d", final[i][j]);
                        lines = lines + 1;
                    }
                    spaces = spaces + 1;
                    if (spaces == m){
                        printf("\n");
                        spaces = 0;
                        lines = 0;
                    }      
                }
            }
            
        } else{
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
        
    }
    
    if (operation == '*'){
        if (n == c){
            int final[n][c];
            int result;
            int lines = 0;
            int spaces = 0;
        
            multiply(n, m, r , c, matrix1, matrix2);
            
            printf("%d %d\n", n, c);
            for (int i = 0; i < n; i++){
                for (int j=0; j< c; j++){
                    if (lines != c && lines >0){
                        printf(" %d", final[i][j]);
                        lines = lines + 1;
                    }
                    if (lines == 0){
                        printf("%d", final[i][j]);
                        lines = lines + 1;
                    }
                    spaces = spaces + 1;
                    if (spaces == c){
                        printf("\n");
                        spaces = 0;
                        lines = 0;
                    }
                }      
            }
        } else{
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
    
    }
    
    return 0;
    
    
    

}

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int x;
    char operation;
    int y;
    int sum = 0;
    int lines = 0;
    int spaces = 0;
    int big_matrix[100];
    int counter = 0;


    /* size of first matrix */
    
    int n;
    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    int matrix1[n][m];



    /* loading of first matrix */
    for (int i = 0; i < n; i++){
        for (int j =0; j < m; j++){
            scanf("%d", &x);
            matrix1[i][j] = x;
                       
        }
    }
    big_matrix[counter] = matrix1[n][m];
    printf("%d", big_matrix[counter]);

    
}

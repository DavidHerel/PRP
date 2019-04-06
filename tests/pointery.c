#include <stdio.h>
#include <stdlib.h>

void shift(char *array_enc, char *array_dec, int counter, int max, int offset, int n1){
    for (int j = -57; j<=57; j++){
            for (int i = 0; i<n1; i++){
       
                if ((array_enc[i]+j)==array_dec[i]){
                    counter = counter + 1;
                    if (counter>max){
                        max = counter;
                        offset = j;
                    }
                }
                
            }
            counter = 0;
        }
      
    


}
int compare(char *array_enc, char *array_dec, int max, int offset, int n1){
    for (int k = 0; k<n1; k++){
        printf("%c", array_enc[k]);
    }
   

}

int main(int argc, char *argv[]){


    char enc;
    int offset = 0;
    int n1 = 0;
    int n2 = 0;
    char dec;
    char *array_enc;
    char *array_dec;
    int counter = 0;
    int max = 0;
    
    
    while (1){
        enc = getchar();
        n1 = n1 + 1;
        if (((enc > 64) && (enc<91)) || (enc>96 && enc<123)){
            array_enc = malloc(sizeof(char));
            array_enc = realloc(array_enc, n1);
            array_enc[n1-1] = enc;
        } else if (enc == '\n'){
            break;
        } else{
            fprintf(stderr, "Error: Chybny vstup!");
            free(array_enc);
            free(array_dec);
            return 100;
        }   
       
    }
   
    
    while (1){
        dec = getchar();
        n2 = n2 + 1;
        if (((dec > 64) && (dec<91))|| (dec>96 && dec<123)){
            array_dec = malloc(sizeof(char));
            array_dec = realloc(array_enc, n2);
            array_dec[n2-1] = dec;
        } else if (dec == '\n'){
            break;
        } else{
            fprintf(stderr, "Error: Chybny vstup!");
            free(array_enc);
            free(array_dec);
            return 100;
        }
       
    }
    if (n1 == n2){
        
        shift(array_enc, array_dec, counter, max, offset, n1);
     
        
        
    }else{
        fprintf(stderr, "Chybna delka vstupu!");
        free(array_enc);
        free(array_dec);
        return 101;
        
    }
    compare(array_enc, array_dec, max, offset, n1);
    printf("\n");
    free(array_enc);
    free(array_dec);
    return 0;
    
    

}

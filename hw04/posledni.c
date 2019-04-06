#include <stdio.h>

int main(void){
    //sito implementace
    int *sito;
    int number = 9454676;
    sito = malloc(sizeof(int)*number);
    
    //napln sita
    for (int i = 0; i<number; i++){
        sito[i]=i;
    }
    
    //vyrazeni
    for (int i = 2; i < number/2; i++){
        for (int j = 2; j < number/2; j++){
            if i*j<number{
            
                sito[j*i]=0;
            } else{
                break;
            
        }
    }
}

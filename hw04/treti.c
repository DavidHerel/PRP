#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    long long int numbers;
    int offset = 0;
    int counter = 1;
    int counter2 = 0;
    for (int i =0; i< counter; i++){ //nekonecny cyklus
        counter = counter +1;// nekonecny cyklus
        if ((scanf("%lli", &numbers))>=1){ //overeni cisla
            if (numbers >1){ //kladna
                long long int number = 9913507;
                long long int i,j;
                int *sito;

                sito = malloc(sizeof(int) * limit);

                for (i = 2;i < limit; i++){
                    sito[i] = i;    
                }
                for (i = 2;i < limit; i++){

                    if (sito[i]!=0){

                        for (i;i * j < limit; j++){

                            sito[i * j] = 0;
                        }
                    }
                }
                printf("Prvociselny rozklad cisla %lli je:\n", numbers);
                for (long long int i = 2; i<=numbers; i++){ //delim to cisly od 2
                    if (sito[i]!=0){
                        while (numbers%sito[i]==0){
                            numbers = numbers/sito[i];
                            counter2 = counter2 +1;
                            
                            if ((numbers%i)!=0){
                                if (offset == 0){
                                    printf ("%d", sito[i]);
                                    offset = offset +1;
                                } else{
                                    printf (" x %d", sito[i]);
                                }
                                if (counter2>=2){
                                    printf ("^%d", counter2);
                                }
                            }
                                
                        }
                        counter2 = 0;
                    }
            
                }
                offset = 0;
                printf("\n");
                   
            }else if (numbers ==1){ // jedna
                printf("Prvociselny rozklad cisla 1 je:\n");
                printf("1\n");
            }else if (numbers ==0){
                
                return 0;                
            }else{ // zbytek
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
        }else{ // zbytek
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
    }
    return 0;
    //tiskni ty cisla
    





}


#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
    long long int numbers;
    int offset = 0;
    int counter = 1;
    int counter2 = 0;
    int sito[1000000];
        
//sito
    for (int i=0; i<1000000; i++){
        sito[i]=i;
    }

    for ( int i = 2; i<1000000; i++){
        for (int j=2; i<1000000; j++){
            if (i*j<1000000){
                sito[i*j]=0;    
                
            } else{
                break;
            }
        }
    }
    for (int i =0; i< counter; i++){ //nekonecny cyklus
        counter = counter +1;// nekonecny cyklus
        if ((scanf("%lli", &numbers))>=1){ //overeni cisla
            if (numbers >1){ //kladna
                printf("Prvociselny rozklad cisla %lli je:\n", numbers);
                for (int i = 2; i<=numbers; i++){ //delim to cisly sitem
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

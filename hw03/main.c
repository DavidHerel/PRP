#include <stdio.h>

int main(void){
    int a;
    int b;
    if ((scanf("%d %d",&a, &b))==2){
        if ((a >= 3 && a <=69) && (b >= 3 && b <=69)){
            if (a%2 == 0){
                fprintf(stderr, "Error: Sirka neni liche cislo!\n");
                return 102;
            } else{
                int c = (a/2);
                for (int i =0; i <c; i++){
                    printf(" ");
                }
                printf("X\n");//prvni X
                
                for (int i=0; i<(c-1);i++){
                    printf(" ");
                }
                printf ("X X\n");
                int f = c-1;
                // tisknu x_x





//neco co mi bude tisknout o mezeru min na zacatku

                int counter = 1;
                int counter2 = 0;
                for (int i =0; i<(f-1); i++){
                    counter = counter +2;
                    counter2 = counter2 +1;                   
                    for (int i =0; i<(f-(counter2)); i++){
                        printf(" ");
                    }
                    
                    
                    
                    
                    
                    
                    
                    printf("X");//mezery mezi X
                    for (int i = 0; i<counter; i++){
                        printf (" ");
                    }
                    printf ("X\n");
                }
                
               
                for (int i=0; i<a; i++){
                    printf ("X");
                }
                printf("\n");
                for (int i=1; i<(b-1); i++){
                    printf ("X");
                    for (int j=1; j<=(a); j++){
                        if (j<(a-1)){
                            printf(" ");
                        } else if (j==a){
                            printf("X\n");
                        }
                        
                    }
                }
                for (int i=0; i<a; i++){
                    printf ("X");
                }
                printf("\n");
                
            }
        } else{
            fprintf (stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }
    } else{
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
}


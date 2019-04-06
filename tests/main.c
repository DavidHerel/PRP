#include <stdio.h>
#include <stdlib.h>

/* The main program */
int main(int argc, char *argv[])
{

int main(int argc, char *argv[])
    int n;
    int counter = 1;
    int numbers = 0;
    int positive = 0;
    int negative = 0;
    float percentage_positive;
    float percentage_negative;
    int even = 0;
    int odd = 0;
    float percentage_even;
    float percentage_odd;
    float sum = 0;
    int min = 0;
    int max = 0;
    for (int i =0; i< counter; i++){
        if ((scanf("%d", &n))==1)
        {
            if ((n >= -10000)&&(n <= 10000)){
                if (i == 0){
                    printf("%d", n);
                    counter = (counter + 1);
                    numbers = (numbers + 1);
                    sum = sum + n;
                    if (n > 0){
                        positive = positive + 1;
                    } else if (n < 0){
                        negative = negative + 1;
                    } if ((n%2) == 0){
                        even = even +1;
                    } else if ((n%2)!=0){
                        odd = odd + 1;
                    } if(n>max){
                        max = n;
                    } if(n<min){
                        min = n;
                    }
                } else{
                  printf(", %d", n);
                  numbers = (numbers  + 1);
                  sum = sum +n;
                  if (n>0){
                    positive = positive +1;
                  } else if (n < 0){
                        negative = negative + 1;
                  } if ((n%2) == 0){
                        even = even +1;
                    } else if ((n%2)!=0){
                        odd = odd + 1;
                    } if(n>max){
                        max = n;
                    } if(n<min){
                        min = n;
                    }      
                }
            counter = (counter + 1);
            } else{
                printf("\nError: Vstup je mimo interval!\n");
                return 100;
                break;
            }
        }
    }
    printf("\nPocet cisel: %d\n", numbers); 
    printf("Pocet kladnych: %d\n", positive);
    printf("Pocet zapornych: %d\n", negative);
    percentage_positive = ((((float)positive)/numbers)*100);
    percentage_negative = ((((float)negative)/numbers)*100);
    printf("Procento kladnych: %.2f\n", percentage_positive);
    printf("Procento zapornych: %.2f\n", percentage_negative);
    printf("Pocet sudych: %d\n", even);
    printf("Pocet lichych: %d\n", odd);
    percentage_even = ((((float)even)/numbers)*100);
    percentage_odd = ((((float)odd)/numbers)*100);
    printf("Procento sudych: %.2f\n", percentage_even);
    printf("Procento lichych: %.2f\n", percentage_odd);
    sum = (sum/numbers);
    printf("Prumer: %.2f\n", sum);
    printf("Maxium: %d\n", max);
    printf("Minimum: %d\n", min);
    return 0;
                 
}

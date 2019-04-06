#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int correct = 0;
    int n1 = 0;
    int n2 = 0;
    char enc;
    char dec;
    char *array_enc;
    char *array_dec;
    int correct_max =0;
    
    array_enc = (char*)malloc(sizeof(char));
    array_dec = (char*)malloc(sizeof(char));
    
    /* plnim pole char prvnim textem */
    while (1)
    {
        enc = getchar();
        
        if (((enc >= 65 && enc <= 90)||(enc >= 97 && enc <= 122))&&(enc != '\n'))
        {
            n1 = n1 + 1;
            array_enc = (char*)realloc(array_enc, n1);
            array_enc[n1-1] = enc;
            
               
        } else if (enc == '\n'){
            break;
        } else{
            fprintf(stderr, "Error: Chybny vstup!\n");
            free (array_enc);
            free (array_dec);
            return 100;
        }
        
    }
  

    /* plnim pole char druhym textem */
    while (1)
    {
        dec = getchar();
        
        if (((dec >= 65 && enc <= 90)||(dec >= 97 && dec <= 122))&&(dec != '\n'))
        {
            n2 = n2 + 1;
            array_dec = (char*)realloc(array_dec, n2);
            array_dec[n2-1] = dec;   
        } else if (dec == '\n'){
            break;
        } else{
            fprintf(stderr, "Error: Chybny vstup!\n");
            free (array_dec);
            free (array_enc);
            return 100;
        }
        
    }

    int move;
    
    /* posouvam char */
    if (n1 == n2){
        for (int i = -56; i < 57; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                if (array_enc[j]<91 && (array_enc[j] + i)>96 && (array_enc[j] + i + 6) == array_dec[j]){
                    correct = correct + 1;
                    if (correct> correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }    
                else if(array_enc[j]>96 && (array_enc[j] + i)>122 && (array_enc[j] + i - 22) == array_dec[j]
                {
                    correct = correct + 1;
                    if (correct> correct_max){
                        correct_max = correct;
                        move=i;
                    }
                
                }    
                else if(array_enc[j]>96 && (array_enc[j] + i)<97 && (array_enc[j] + i - 6) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct> correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                else if(array_enc[j]<91 && (array_enc[j] + i)<65 && (array_enc[j] + i + 58) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct> correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                else if(array_enc[j]+i == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct> correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                
            }
            correct = 0;
        }
    } else{
        fprintf(stderr, "Error: Chybna delka vstupu!\n");
            free (array_enc);
            free (array_dec);
            return 101;      
    }
    for (int k = 0; k< n1; k++){

        if (array_enc[k]<91 && (array_enc[k]+move)>90){
            
            printf("%c",  (array_enc[k]+(-65+move))%57 + 65 +6);
        }
        else if (array_enc[k]+move > 122)
        {
            printf("%c",  (array_enc[k]+move-58));
        }

        else{
            printf("%c",  (array_enc[k]+(-65+move))%57 + 65);
        }

       
    }
    printf ("\n%d\n", move);
    printf ("%d\n", correct_max);
    printf ("\n");
    free (array_dec);
    free (array_enc);
    return 0;
}
 
    

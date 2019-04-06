#include <stdio.h>
#include <stdlib.h>
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

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
    int mat1;
    int mat2;
    
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
                if(array_enc[j]<91 && (array_enc[j] + i)<65 && (array_enc[j] + i + 58)<97 && (array_enc[j] + i + 58) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct> correct_max){
                        correct_max = correct;
                        move=i;
                    }
                
                }    
                else if(array_enc[j]>96 && (array_enc[j] + i)<97 && (array_enc[j] + i - 6)<65 && (array_enc[j] + i + 52) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                
                } 
                else if (array_enc[j]<91 && (array_enc[j] + i)>90 && (array_enc[j] + i + 6) == array_dec[j]){
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }    
                else if(array_enc[j]>96 && (array_enc[j] + i)>122 && (array_enc[j] + i - 58) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                
                }    
                else if(array_enc[j]>96 && (array_enc[j] + i)<97 && (array_enc[j] + i - 6) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                else if(array_enc[j]<91 && (array_enc[j] + i)<65 && (array_enc[j] + i + 58) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                else if(array_enc[j]+i == array_dec[j] &&((array_enc[j]<91 && array_enc[j]+i<91)||(array_enc[j]>96 && array_enc[j]+i>96)))
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                
            }
            correct = 0;
        }
    } else{
    /*
        mat1 = [n1][n2];
        for (int i = 0; i<n1; i++){
            mat1[i][0]=i;
        }
        for (int i = 0; i<n2; i++){
            mat1[0][i]=i;
        }
        for (int i = 1; i<n1; i++){
            for (int j = 1; j<n2; j++){
                if (array_enc[i] == array_dec[j]){
                    mat1[i][j]=mat1[i-1][ j-1];
                
                }else{
                    mat1[i][j]=   
                }
            } 
        }
      */
        for (int i = -56; i < 57; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                if(array_enc[j]<91 && (array_enc[j] + i)<65 && (array_enc[j] + i + 58)<97 && (array_enc[j] + i + 58) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct> correct_max){
                        correct_max = correct;
                        move=i;
                    }
                
                }    
                else if(array_enc[j]>96 && (array_enc[j] + i)<97 && (array_enc[j] + i - 6)<65 && (array_enc[j] + i + 52) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                
                } 
                else if (array_enc[j]<91 && (array_enc[j] + i)>90 && (array_enc[j] + i + 6) == array_dec[j]){
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }    
                else if(array_enc[j]>96 && (array_enc[j] + i)>122 && (array_enc[j] + i - 58) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                
                }    
                else if(array_enc[j]>96 && (array_enc[j] + i)<97 && (array_enc[j] + i - 6) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                else if(array_enc[j]<91 && (array_enc[j] + i)<65 && (array_enc[j] + i + 58) == array_dec[j])
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                else if(array_enc[j]+i == array_dec[j] &&((array_enc[j]<91 && array_enc[j]+i<91)||(array_enc[j]>96 && array_enc[j]+i>96)))
                {
                    correct = correct + 1;
                    if (correct>= correct_max){
                        correct_max = correct;
                        move=i;
                    }
                }
                
            }
            correct = 0;
        }
        
        for (int k = 0; k< n1; k++){
            if(array_enc[k]<91 && (array_enc[k] + move)<65 && (array_enc[k] + move + 58)<97)
            {
                printf("%c", array_enc[k]+move+58-6);
            } 
            else if(array_enc[k]>96 && (array_enc[k] + move)<97 && (array_enc[k] + move - 6)<65)
            {
                printf("%c", array_enc[k]+move-6+58);
            }
            else if(array_enc[k]>96 && (array_enc[k] + move)>122 && (array_enc[k] + move - 58)>90)
            {
                printf("%c", array_enc[k]+move-52);
            }   
            else if (array_enc[k]<91 && (array_enc[k] + move)>122)
            {
               printf("%c", array_enc[k]+move-52);
            } 
            else if (array_enc[k]<91 && (array_enc[k] + move + 6)>122 )
            {
               printf("%c", array_enc[k]+move-52);
            } 
            else if (array_enc[k]<91 && (array_enc[k] + move)>90)
            {
               printf("%c", array_enc[k]+move+6);
            }  
            else if(array_enc[k]>96 && (array_enc[k] + move)>122)
            {
                printf("%c", array_enc[k]+move-58);
            }    
            else if(array_enc[k]>96 && (array_enc[k] + move)<97)
            {
                printf("%c", array_enc[k]+move-6);
            }
            else if(array_enc[k]<91 && (array_enc[k] + move)<65)
            {
                printf("%c", array_enc[k]+move+58);
            }
            else
            {
                printf("%c", array_enc[k]+move);
            }

       
        }
        
        
      
       

              
    }
    if (n1 == n2)
        for (int k = 0; k< n1; k++){
            if(array_enc[k]<91 && (array_enc[k] + move)<65 && (array_enc[k] + move + 58)<97)
            {
                printf("%c", array_enc[k]+move+58-6);
            } 
            else if(array_enc[k]>96 && (array_enc[k] + move)<97 && (array_enc[k] + move - 6)<65)
            {
                printf("%c", array_enc[k]+move-6+58);
            }
            else if(array_enc[k]>96 && (array_enc[k] + move)>122 && (array_enc[k] + move - 58)>90)
            {
                printf("%c", array_enc[k]+move-52);
            }   
            else if (array_enc[k]<91 && (array_enc[k] + move)>122)
            {
               printf("%c", array_enc[k]+move-52);
            } 
            else if (array_enc[k]<91 && (array_enc[k] + move + 6)>122 )
            {
               printf("%c", array_enc[k]+move-52);
            } 
            else if (array_enc[k]<91 && (array_enc[k] + move)>90)
            {
               printf("%c", array_enc[k]+move+6);
            }  
            else if(array_enc[k]>96 && (array_enc[k] + move)>122)
            {
                printf("%c", array_enc[k]+move-58);
            }    
            else if(array_enc[k]>96 && (array_enc[k] + move)<97)
            {
                printf("%c", array_enc[k]+move-6);
            }
            else if(array_enc[k]<91 && (array_enc[k] + move)<65)
            {
                printf("%c", array_enc[k]+move+58);
            }
            else
            {
                printf("%c", array_enc[k]+move);
            }

           
        }
   // printf ("\n%d\n", move);
   // printf ("%d\n", correct_max);
    printf ("\n");
    free (array_dec);
    free (array_enc);
    return 0;
}
 
    

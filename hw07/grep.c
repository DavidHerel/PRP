#include <stdio.h>
#include <stdlib.h>

#define INF "\x1b[01;31m\x1b[K"
#define BE "\x1b[m\x1b[K"
 
int main(int argc, char *argv[]){
    FILE *file;
    char *text;
    int index = 0;
    char letter;
    int array_len = 0;
    int count = 0;
    char *spaces;
    int *memory;
    int letter_size = 1;
    int count_arr = 1;
    int succ = 0;
    int c_p = 0;
    int countC = 0;;
    int iz = 2;
    int red = 0;
    
    spaces = malloc(sizeof(char));
    text = malloc(sizeof(char));
    memory = malloc(sizeof(int));
     
    if(argc==3){
        for (int i = 0; i < sizeof(argv[1]); i++){
            if (argv[1][i] != '\0'){
                letter_size = letter_size + 1;
            } else{
                break;
            }
        }
        file = fopen(argv[2], "r");
        if (file == 0){
            fprintf(stderr, "Error in opening file\n");
            free(memory);
            free(text);
            free(spaces);
            //  fclose(file);
            return 100;
        }
 
 
        while ((letter = getc(file))!=EOF){
            array_len = array_len + 1;
            //  printf("%c", letter);
            index = index + 1;
            text = realloc(text, (sizeof(char) * index));
            text[index-1] = letter;
            //  printf("%c", letter);
        }
 
    }
    else if(argc == 2){
        for (int i = 0; i < sizeof(argv[1]); i++){
            if (argv[1][i] != '\0'){
                letter_size = letter_size + 1;
            } else{
                break;
            }
        }
        while ((letter = getchar())!=EOF){
            array_len = array_len + 1;
            index = index + 1;
            text = realloc(text, (sizeof(char) * index));
            text[index-1] = letter;
        }
    }
    else{
        for (int i = 0; i < sizeof(argv[1]); i++){
            if (argv[2][i] != '\0'){
                letter_size = letter_size + 1;
            } else{
                break;
            }
        }
        file = fopen(argv[3], "r");
        if (file == 0){
            fprintf(stderr, "Error in opening file\n");
            free(memory);
            free(text);
            free(spaces);
            //  fclose(file);
            return 100;
        }
 
 
        while ((letter = getc(file))!=EOF){
            array_len = array_len + 1;
            //  printf("%c", letter);
            index = index + 1;
            text = realloc(text, (sizeof(char) * index));
            text[index-1] = letter;
            //  printf("%c", letter);
        }
        for (int i = 0; i < array_len; i++){
            count = 0;
            if (text[i] != '\n'){
                spaces = realloc(spaces, (sizeof(char) * count_arr));
                spaces[count_arr-1]= text[i];
                 
                 
                count_arr++;
            }
            else{     
                for (int j = 0; j < (count_arr-1); j++){
                 
                    if(spaces[j]==argv[2][count]){
                        count++;
                        c_p = c_p + 1;
                        
                        if (c_p == (letter_size-1)){;
                            for (int k = 0; k < count_arr-1; k++){
                                if ((argv[2][countC] == spaces[k])&& (spaces[k+(letter_size-iz)] == argv[2][countC + (letter_size-iz)])){
                                    countC = countC + 1;
                                    iz = iz + 1;
                                    if (red ==0){
                                        printf(INF);
                                        red = 1;
                                    }
                                    printf("%c", spaces[k]);

                                } else{
                                    if (red == 1){
                                        printf(BE);
                                        red = 0;
                                        
                                    }
                                    printf("%c", spaces[k]);
                                    countC = 0;
                                    iz = 2;
                                }
                             //I am stuck
                            }
                            if (red == 1){
                                printf(BE);
                                red = 0;
                                        
                            }
                            succ++;
                            printf("\n");
                            break;
                        }
                    } else{
                        c_p = 0;
                        count = 0;
                    }
                }
                count_arr = 1;

            }
            c_p = 0;
             
        }
         
        free(memory);
        free(text);
        free(spaces);
        if (argc == 4){
            fclose(file);
        }
        if(succ>0){
            return 0;
        }
        else{
            return 1;
        }
        
    }
    for (int i = 0; i < array_len; i++){
        count = 0;
        if (text[i] != '\n'){
            spaces = realloc(spaces, (sizeof(char) * count_arr));
            spaces[count_arr-1]= text[i];
             
             
            count_arr++;
        }
        else{     
            for (int j = 0; j < (count_arr-1); j++){
             
                if(spaces[j]==argv[1][count]){
                    count++;
                    c_p = c_p + 1;
                    
                    if (c_p == (letter_size-1)){
                        for (int k = 0; k < count_arr-1; k++){
                            printf("%c", spaces[k]);
                         
                        }
                        succ++;
                        printf("\n");
                        break;
                    }
                } else{
                    c_p = 0;
                    count = 0;
                }
            }
            count_arr = 1;

        }
        c_p = 0;
         
    }
     
    free(memory);
    free(text);
    free(spaces);
    if (argc == 3){
        fclose(file);
    }
    if(succ>0){
        return 0;
    }
    else{
        return 1;
    }
 
}

#include <stdio.h>
#include <stdlib.h>

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

    for (int i = 0; i < sizeof(argv[1]); i++){
        if (argv[1][i] != '\0'){
            letter_size = letter_size + 1;
        } else{
            break;
        }
    }
    spaces = malloc(sizeof(char));
    text = malloc(sizeof(char));
    memory = malloc(sizeof(int));
    
    if(argc==3){
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
    if (argc == 2){
        while ((letter = getchar())!=EOF){
            array_len = array_len + 1;
            index = index + 1;
            text = realloc(text, (sizeof(char) * index));
            text[index-1] = letter;
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
                    if (count == (letter_size-1)){
                        for (int k = 0; k < count_arr-1; k++){
                            printf("%c", spaces[k]);
                        
                        }
                        succ++;
                        printf("\n");
                        break;
                    }
                }
            }
            count_arr = 1;
        }
        
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

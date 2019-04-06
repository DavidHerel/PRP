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
    int x, p;
    int *memory;
    int memc = 0;
    int letter_size = 1;
    int count_arr = 0;

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
    

    file = fopen(argv[2], "r");
    if (file == 0){
        fprintf(stderr, "Error in opening file\n");
        free(memory);
        free(text);
        free(spaces);
     //   fclose(file);
        return 100;
    }


    while ((letter = getc(file))!=EOF){
        array_len = array_len + 1;
       // printf("%c", letter);
        index = index + 1;
        text = realloc(text, (sizeof(char) * index));
        text[index-1] = letter;
        //  printf("%c", letter);
    }
    for (int i = 0; i < array_len; i++){
        count_arr = count_arr + 1;
        if (text[i] != '\n'){
            spaces = realloc(spaces, (sizeof(char) * count_arr));
            spaces[i] = text[i];
            count = 0;
            
            
            
        
        }
        else{
       // printf("%d", letter_size);
            for (int j = 0; j < (i); j++){
                if(spaces[j]==argv[1][count]){
                    count++;
                    printf("count:%d letter:%c\n", count, argv[1][count-1]);
                   if (count == (letter_size-1)){
                        printf("%d", memory[memc-3]);
                        for (int k = memory[memc-2]; k < j; k++){
                            printf("%c", spaces[k]);
                        
                        }
                        printf("\n");
                        free(memory);
                        free(text);
                        free(spaces);
                        fclose(file);
                        return 0;
                    }
                    
                }
                
            }
            printf("\n");
            memc = memc + 1;
           
            memory = realloc(memory, sizeof(int) * memc);
            memory[memc-1] = i;
            
        }
    }
    
    free(memory);
    free(text);
    free(spaces);
    fclose(file);
    return 1;
    

}

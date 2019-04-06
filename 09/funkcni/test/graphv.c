#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"

/* This is a testing file just to be able to compile the 
 * examples of binary files to convert graph from txt->bin
 * and bin -> txt
 */

// - function -----------------------------------------------------------------
graph_t* allocate_graph() {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_edges = 0;
    graph->capacity = 0;
    return graph;    
}

// - function -----------------------------------------------------------------
void free_graph(graph_t **graph){
    free((*graph)->edges);  
    free(*graph);
    *graph = NULL;
}

// - function -----------------------------------------------------------------
void load_txt(const char *fname, graph_t *graph){
    int twicer = 10;
    char enc;
    int n1 = 0;
    int count = 0;
    char *array_enc;
    char *array_enc2;
    char *array_enc3;
    int cou = 0;
    FILE *file = fopen(fname, "r");
    while (1){

        if (feof(file) == 1){
            break;
        }
        if (graph->num_edges == graph->capacity){
                   
            graph->edges = realloc(graph->edges, twicer * sizeof(edge_t));
            graph->capacity = twicer;
            twicer = twicer * 2;
        }
        edge_t *stru = graph->edges + graph->num_edges;
        while (1){
            if (graph->num_edges == graph->capacity){
                break;
            }
            array_enc = (char*)malloc(sizeof(char));
            array_enc2 = (char*)malloc(sizeof(char));
            array_enc3 = (char*)malloc(sizeof(char));
            while (1){
                enc = fgetc(file);
                if (feof(file)){
                    break;
                }
                if (enc == ' '){
                    cou++;
                    n1 = 0;
                } else{
                    if (cou == 0){
                        n1 = n1 + 1;
                        array_enc = (char*)realloc(array_enc, n1);
                        array_enc[n1-1] = enc;
                    } else if (cou == 1){
                        n1 = n1 + 1;
                        array_enc = (char*)realloc(array_enc2, n1);
                        array_enc[n1-1] = enc;
                    } else if (cou == 2){
                        n1 = n1 + 1;
                        array_enc = (char*)realloc(array_enc3, n1);
                        array_enc[n1-1] = enc;
                    }
                }
            }
            stru->from = atoi(array_enc);
            count++;
            free(array_enc);
            stru->to = atoi(array_enc2);
            count++;
            free(array_enc2);
            stru->cost = atoi(array_enc3);
            count++;
            free(array_enc3);
            //int count = fscanf(file, "%d %d %d\n", &(stru->from), &(stru->to), &(stru->cost));
            //fprintf(stderr, "%d %d %d\n", (stru->from), (stru->to), (stru->cost));
            if(count == 3){
                graph->num_edges += 1;
                stru += 1;
                count = 0;
            }else{
                break;
            }
        }
        
    }
    fclose(file);
   // fprintf(stderr, "ahoj\n");
}

// - function -----------------------------------------------------------------
void load_bin(const char *fname, graph_t *graph){
    //int exit = 0;
    int twicer = 10;
    FILE *file = fopen(fname, "rb");
    while (1){

        if (feof(file) == 1){
            break;
        }
        if (graph->num_edges == graph->capacity){
                   
            graph->edges = realloc(graph->edges, twicer * sizeof(edge_t));
            graph->capacity = twicer;
            twicer = twicer * 2;
        }
        edge_t *stru = graph->edges + graph->num_edges;
        while (1){
            if (graph->num_edges == graph->capacity){
                break;
            }
            int first = fread(&(stru->from), 4, 1, file);
            int second =fread(&(stru->to), 4, 1, file);
            int third = fread(&(stru->cost), 4, 1, file);
            //fprintf(stderr, "%d %d %d\n", (stru->from), (stru->to), (stru->cost));
            if(first + second + third == 3){
                graph->num_edges += 1;
                stru += 1;
            }else{
                break;
            }
        }
        
    }
    fclose(file);
}


// - function -----------------------------------------------------------------
void save_txt(const graph_t * const graph, const char *fname){
    FILE *file;
    int i = 0;
    file = fopen(fname, "w");
    edge_t *stru = graph->edges;
    while (1){
        if (i == graph->num_edges){
            break;
        } else{
            fprintf(file,"%d %d %d\n", stru->from, stru->to, stru->cost);
            stru++;
            i++;
        }
    }   
    fclose(file);
}

// - function -----------------------------------------------------------------
void save_bin(const graph_t * const graph, const char *fname){
    FILE *file;
    int i = 0;
    file = fopen(fname, "wb");
    edge_t *stru = graph->edges;
    while (1){
        if (i == graph->num_edges){
            break;
        } else{
            fwrite(&(stru->from), 4, 1, file);
            fwrite(&(stru->to), 4, 1, file);
            fwrite(&(stru->cost), 4, 1, file);
            stru++;
            i++;
        }
    }
    fclose(file);
}

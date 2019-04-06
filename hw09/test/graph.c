#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include <string.h>

/* This is a testing file just to be able to compile the 
 * examples of binary files to convert graph from txt->bin
 * and bin -> txt
 */

// - function -----------------------------------------------------------------
graph_t* allocate_graph() {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->edge1 = malloc(sizeof(int));
    graph->edge2 = malloc(sizeof(int));
    graph->value = malloc(sizeof(int));
    graph->index = 0;
    graph->bin = malloc(sizeof(int));
    return graph;
}

// - function -----------------------------------------------------------------
void free_graph(graph_t **graph){
}

// - function -----------------------------------------------------------------
void load_txt(const char *fname, graph_t *graph){
    char end;
    int ed1;
    int ed2;
    int val;
    FILE *file;
    file = fopen(fname, "r+");
    graph->index = 0;
    int index = 0;
    while (1){
        if ((end = getc(file)==EOF)){
            fclose(file);
            break;
        }
        if ((fscanf(file, "%d", &ed1))!= 1){
            break;
        }
        if ((fscanf(file, "%d", &ed2))!= 1){
            break;
        }
        if ((fscanf(file, "%d", &val))!= 1){
            break;;
        }
        graph->edge1[graph->index] = ed1;
        graph->edge2[graph->index] = ed2;
        graph->value[graph->index] = val;
        
        graph->index++;
        graph->edge1 = realloc(graph->edge1, (index+1)*sizeof(int));
        graph->edge2 = realloc(graph->edge2, (index+1)*sizeof(int));
        graph->value = realloc(graph->value, (index+1)*sizeof(int));
    
    }
}

// - function -----------------------------------------------------------------
void load_bin(const char *fname, graph_t *graph){
    FILE *file;
    char end;
    file = fopen(fname, "rb");
    graph->bin = malloc(sizeof(int*)*(graph->index*3));
    while (1){
        if ((end = getc(file)==EOF)){
            fclose(file);
            break;
        }
        if (fread(graph->bin, sizeof(graph_t), 1, file)!=1){
            break;
        }
    }
    

}

// - function -----------------------------------------------------------------
void save_txt(const graph_t * const graph, const char *fname){
    FILE *file;
    file = fopen(fname, "a");
    for (int i = 0; i < graph->index; i++){
        fprintf(file, "%d %d %d\n", graph->edge1[i], graph->edge2[i], graph->value[i]);
    }
    fclose(file);
}

// - function -----------------------------------------------------------------
void save_bin(const graph_t * const graph, const char *fname){
    FILE *file;
    file = fopen(fname, "ab");
    for (int i = 0; i < graph->index; i++){
        fwrite(&graph->edge1[i], sizeof(graph_t), 1, file);
        fwrite(&graph->edge2[i], sizeof(graph_t), 1, file);
        fwrite(&graph->value[i], sizeof(graph_t), 1, file);
    }
    fclose(file);
    
}

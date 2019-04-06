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
    graph->edges = NULL;
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
            int r = fscanf(file, "%d %d %d", &(stru->from), &(stru->to), &(stru->cost));
            //fprintf(stderr, "%d %d %d\n", (stru->from), (stru->to), (stru->cost));
            if(r == 3){
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

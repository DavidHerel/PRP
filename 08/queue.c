#include "queue.h"
#include <stdlib.h>
 
 
queue_t* create_queue(int capacity){
    queue_t *queue = malloc(sizeof(queue_t));
    queue->start = 0;
    queue->end = 0;
    queue->size = capacity;
    queue->arr = malloc(queue->size*sizeof(void*));
    queue->value = 0;
    queue->element = 0;
    return queue;
}
 
void delete_queue(queue_t *queue){
    free(queue->arr);
    free(queue);
}
 
bool push_to_queue(queue_t *queue, void* data){ 
    queue->value++;
    if (queue->value < (queue->size)*(1/3)){
        queue->size = ((queue->size)*(1/3));
        queue->arr = realloc(queue->arr, queue->size*sizeof(void*));
    } else if (queue->value > queue->size){
        queue->size = ((queue->size)*2);
        queue->arr = realloc(queue->arr, queue->size*sizeof(void*));
    }
     
    queue->end=(queue->end)%queue->size;
    queue->arr[queue->end] = data;
    queue->end++;
 
    return true;
 
}
 
void* pop_from_queue(queue_t *queue){
    if(queue->value == 0){ //empty
        return NULL;
    } else{
        queue->value--;
        queue->element = queue->arr[queue->start];
        queue->start = (queue->start+1)%queue->size;
 
        return queue->element;
    }
}
 
void* get_from_queue(queue_t *queue, int idx){
    if ((idx >= 0) && (idx+1 <= queue->value)){
        return queue->arr[queue->start+idx];
    } else{
        return NULL;
    }
}
 
int get_queue_size(queue_t *queue){
    return queue->value;
}
    

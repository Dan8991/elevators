#include "node.h"
#include <stdlib.h>

node_t *create_node(void *value){

    node_t *ret = malloc(sizeof(node_t));

    ret->value = value;
    ret->next = NULL; 
    return ret;
}

node_t *free_node(node_t *node, void (*free_value)(void*)){

    if(free_value){
        free_value(node->value);
    }

    free(node);
    return NULL;
}
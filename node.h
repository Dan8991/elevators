#ifndef LIST_H
#define LIST_H


typedef struct node{
    void *value;
    node_t *next;
} node_t;

node_t *create_node(void *value);

node_t *free_node(node_t *node, void (*free_value)(void*));

#endif
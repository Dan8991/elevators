#ifndef LIST_H
#define LIST_H

/*
node of a linked_list, contains a reference to the previous and next nodes
and also a generic pointer to a value
*/
typedef struct node
{
    void *value;
    struct node *previous;
    struct node *next;
}
node_t;

/*
*constructor of a node, memory is allocated in the heap so it needs to be freed
* value = pointer to the value to be incapsulated in the node
* returns a pointer to the newly created node
*/
node_t *create_node(void *value);

/*
*Function used to free a node and it's value
* node = node to be freed
* free_value = function that frees the memory of the value contained in the node
* returns NULL
*/
node_t *free_node(node_t *node, void free_value(void*));

#endif

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

//value to be returned when a function couldn't execute
#define FAILED_EXECUTION -1
//value to be returned when a function executed properly
#define CORRECT_EXECUTION 1

/* 
*linked list where the nodes contain a void* value so they are generic
* head = first node of the list and it is always empty
* tail = last node of the list, if the list is empty tail==head
* iterator = pointer to a node used to access elements in the middle of the list
* length = length of the list
*/
typedef struct linked_list
{
    node_t *head;
    node_t *tail;
    node_t *iterator;
    int length;
}
linked_list_t;

/*
*constructor of the list, heap memory is allocated
*so it needs to be freed
*returns an empty list
*/
linked_list_t *create_list();

/*
*Appends a node at the end of the list and the iterator is reset in order to 
*prevent strange behaviours
* list = list where the node is appended 
* value = value that is saved in the node
* returns 1 if the node was added -1 if there were problems.
*/
int add(linked_list_t *list, void* value);

/*
*Removes first node from the list freeing it from memory
*Resets iterator in order to prevent strange behaviours
* my_list = list where the node is removed 
* returns the value in the removed node, if there isn't a first
* node or if the list is not defined the function returns NULL
*/
void *remove_first(linked_list_t *my_list);

/*
*Frees all the memory in the list that was allocated dynamically
* my_list = list that has to be freed 
* remove_val = function used to free the memory of the value in each node
* if NULL then no function is used to free the values.
* returns NULL
*/
linked_list_t *free_linked_list(linked_list_t *my_list, void remove_val(void*));

/*
*Mooves forward the iterator
* my_list = list containing the iterator to be mooved 
* returns the value in the node where the iterator is placed after mooving
*/
void* move_next(linked_list_t *my_list);

/*
*Mooves the iterator back to the head of the list
* my_list = list containing the iterator to be resetted 
* returns the value in the node where the iterator is placed after mooving
*/
int reset_iterator(linked_list_t *my_list);

/*
*Checks if the iterator has arrived at the end of the list
* my_list = list containing the iterator
* returns 1 if the iterator can be mooved forward 0 if not and
* FAILED_EXECUTION if my_list was NULL
*/
int iter_has_next(linked_list_t *my_list);

/*
*Checks if the list is empty
* my_list = list to be checked
* returns 1 if the list is empty 0 if it is not and FAILED_EXECUTION
* if my_list is NULL
*/
int list_is_empty(linked_list_t *my_list);


/*
*Returns the value of the node pointed by the iterator
* my_list = list containing the iterator 
* returns the value contained in the node pointed by the 
* iterator, if my_list is NULL it returns NULL
*/
void *get_current_iter_value(linked_list_t *my_list);

/*
*Returns the length of the list
* my_list = list whoose length has to be evaluated
* returns the length of the list, FAILED_EXECUTION if my_list is NULL 
*/
int linked_list_length(linked_list_t *my_list);

/*
*removes the node pointed by the iterator, the iterator then points to the
*previous node
* my_list = list containing the iterator
* free_value = function that frees the memory of the value in the node
* returns CORRECT_EXECUTION if everything went well, FAILED_EXECUTION if 
* my_list is NULL or if the iterator points to the head of the list
*/
int remove_current_iter_node(linked_list_t *my_list, void free_value(void*));

/*
*Returns a String that represents the list
*Resets the iterator since it is used to traverse the list
* list_string = String where the representation will be saved
* list = list to be transformed into a string
* val_to_string = function that transform the value of the nodes in a string
*	val_string = string that will contain the string representation of the value
*	of the node
*   val = value to be represented as a string
*   it has to return val_string
* max_val_string_length = tells the max length of the string representing 
* the node's value 
*returns list_string unless list is NULL, in that case it returns NULL
*/
char *linked_list_to_string(char* list_string, linked_list_t *list,
        char *val_to_string(char* val_string, void* val),int max_val_string_length);
#endif

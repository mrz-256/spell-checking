#pragma once

#include <malloc.h>


typedef struct node_t {
    char *value;
    struct node_t *next;
} node_t;

typedef struct linkedlist {
    node_t *head;
} linkedlist_t;


/// creates linked list node
node_t *node_create(const char *value, node_t *next);

/// creates linked list
linkedlist_t *linkedlist_create();

/// returns linked list size
unsigned int linkedlist_size(linkedlist_t *linkedlist);

/// pushes value to the end of linked list
void linkedlist_pushback(linkedlist_t *linkedlist, const char *value);

/// pushes value to the beginning of linked list
void linkedlist_pushfront(linkedlist_t *linkedlist, const char *value);

/// inserts value into the linked list
void linkedlist_insert(linkedlist_t *linkedlist, const char *value, int position);

/// returns value from linked list
char *linkedlist_get(linkedlist_t *linkedlist, int position);

void linkedlist_set(linkedlist_t *linkedlist, int position, const char* value);

/// returns 1 if linked list contains given value
int linkedlist_contains(linkedlist_t *linkedlist, const char *value);

/// frees linked list
void linkedlist_free(linkedlist_t* linkedlist);

#include <string.h>
#include "linkedlist.h"


node_t *node_create(const char *value, node_t *next)
{
    node_t *node = malloc(sizeof(node_t));

    // set values
    node->value = malloc(strlen(value) + 1);
    strcpy(node->value, value);

    node->next = (struct node_t *) next;

    return node;
}

linkedlist_t *linkedlist_create()
{
    linkedlist_t *list = malloc(sizeof(linkedlist_t *));
    list->head = NULL;
    return list;
}

unsigned int linkedlist_size(linkedlist_t *linkedlist)
{
    if (linkedlist == NULL)
    {
        return 0;
    }

    unsigned int size = 0;

    node_t *head = linkedlist->head;
    while (head != NULL)
    {
        size++;
        head = (node_t *) head->next;
    }
    return size;
}

char *linkedlist_get(linkedlist_t *linkedlist, int position)
{
    if (linkedlist == NULL || linkedlist->head == NULL)
    {
        return NULL;
    }

    int index = 0;
    node_t *node = linkedlist->head;

    while (node != NULL && index != position)
    {
        node = node->next;
        index++;
    }

    if (node == NULL)
    {
        return NULL;
    }

    return node->value;
}

void linkedlist_set(linkedlist_t *linkedlist, int position, const char *value)
{
    if (linkedlist == NULL)
    {
        return;
    }

    int index = 0;
    node_t *node = linkedlist->head;

    while (node != NULL)
    {
        if (index == position)
        {
            free(node->value);
            node->value = malloc(strlen(value) + 1);
            strcpy(node->value, value);
            return;
        }
        node = node->next;
        index++;
    }
}

void linkedlist_pushback(linkedlist_t *linkedlist, const char *value)
{
    // if there's no head just put it there
    if (linkedlist == NULL || linkedlist->head == NULL)
    {
        linkedlist->head = node_create(value, NULL);
        return;
    }

    node_t *head = linkedlist->head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = node_create(value, NULL);
}

void linkedlist_pushfront(linkedlist_t *linkedlist, const char *value)
{
    if (linkedlist == NULL)
    {
        return;
    }
    node_t *new_head = node_create(value, linkedlist->head);
    linkedlist->head = new_head;
}

void linkedlist_insert(linkedlist_t *linkedlist, const char *value, int position)
{
    if (linkedlist == NULL)
    {
        return;
    }

    if (position == 0)
    {
        linkedlist_pushfront(linkedlist, value);
        return;
    }
    if (linkedlist->head == NULL)
    {
        linkedlist->head = node_create(value, NULL);
        return;
    }

    int index = 0;
    node_t *node = linkedlist->head;

    while (index < position && node->next != NULL)
    {
        node = node->next;
        index++;
    }
    // if index is beyond linked list, put it at the end
    if (node->next == NULL)
    {
        node->next = node_create(value, NULL);
        return;
    }

    // actually insert it
    node->next = node_create(value, node->next);
}

int linkedlist_contains(linkedlist_t *linkedlist, const char *value)
{
    if (linkedlist == NULL || linkedlist->head == NULL)
    {
        return 0;
    }

    node_t *head = linkedlist->head;
    while (head != NULL)
    {
        if (strcmp(head->value, value) == 0)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

void linkedlist_free(linkedlist_t *linkedlist)
{
    if (linkedlist == NULL)
    {
        return;
    }

    node_t *head = linkedlist->head;
    node_t *next;
    while (head != NULL)
    {
        next = head->next;
        free(head->value);
        free(head);
        head = next;
    }
    free(linkedlist);
}


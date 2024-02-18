#pragma once

#include "../datastructures/linkedlist.h"
#include "../algorithms/stringdistance.h"
#include <string.h>
#include <ctype.h>

typedef struct dictionary_t {
    linkedlist_t *words;
} dictionary_t;

/// loads all valid words
dictionary_t *dictionary_load(const char *path);

/// frees dictionary
void dictionary_free(dictionary_t *dictionary);

/// prints all words in dictionary to console
void dictionary_dump(dictionary_t *dictionary);


/// returns the closest word in the dictionary(can be equal word)
char *dictionary_get_closest(dictionary_t *dictionary, const char *word);

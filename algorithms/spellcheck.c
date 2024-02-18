#include "spellcheck.h"

dictionary_t *dictionary_load(const char *path)
{
    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        return NULL;
    }

    dictionary_t *dictionary = malloc(sizeof(dictionary_t));
    dictionary->words = linkedlist_create();

    char line[30];
    while (fgets(line, 30, file) != NULL)
    {
        line[strcspn(line, "\n")] = 0;
        line[strcspn(line, "\r")] = 0;
        linkedlist_pushback(dictionary->words, line);
    }
    fclose(file);

    return dictionary;
}

void dictionary_free(dictionary_t *dictionary)
{
    linkedlist_free(dictionary->words);
    free(dictionary);
}

void dictionary_dump(dictionary_t *dictionary)
{
    unsigned int size = linkedlist_size(dictionary->words);
    for (int i = 0; i < size; ++i)
    {
        char* word = linkedlist_get(dictionary->words, i);
        if (word != NULL)
        {
            printf("%s\n", word);
        }
    }
}


char *dictionary_get_closest(dictionary_t* dictionary, const char *word)
{
    unsigned int size = linkedlist_size(dictionary->words);
    int closest_word = 0;
    int least_str_difference = (int)INFINITY;

    char* lower_word = malloc(strlen(word) + 1);
    for(int i=0; i<strlen(word); i++)
    {
        lower_word[i] = (char) tolower(word[i]);
    }

    for (int i = 0; i < size; ++i)
    {
        char* dic_word = linkedlist_get(dictionary->words, i);

        // if the `word` is in dictionary
        if (strcmp(lower_word, dic_word) == 0)
        {
            return dic_word;
        }

        // if not, check the closest
        int difference = calculate_string_distance(lower_word, dic_word);
        if (difference < least_str_difference)
        {
            least_str_difference = difference;
            closest_word = i;
        }
    }
    free(lower_word);

    return linkedlist_get(dictionary->words, closest_word);
}

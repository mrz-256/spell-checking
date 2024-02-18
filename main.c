#include <stdio.h>
#include "datastructures/linkedlist.h"

#include "algorithms/spellcheck.h"

int main()
{

    dictionary_t *dictionary = dictionary_load("../words_alpha.txt");
    if (dictionary == NULL)
    {
        printf("failed loading dictionary");
        return 1;
    }

    char *closest_word = dictionary_get_closest(dictionary, "sPeLlin");
    if (closest_word == NULL)
    {
        printf("error with closest_word");
    } else
    {
        printf("%s\n", closest_word);
    }




    return 0;
}

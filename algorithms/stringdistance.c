#include "stringdistance.h"

#define min(a, b) ((a<b)?a:b)

int calculate_string_distance(const char *s1, const char *s2)
{
    // lengths
    unsigned int l1 = strlen(s1);
    unsigned int l2 = strlen(s2);

    // create table
    int **table = malloc(sizeof(int *) * (l1 + 1));

    // fill the first row and the first column with default values
    for (int i = 0; i < l1 + 1; ++i)
    {
        table[i] = malloc(sizeof(int) * (l2 + 1));
        table[i][0] = i;
    }
    for (int i = 0; i < l2 + 1; ++i)
    {
        table[0][i] = i;
    }
    table[1][1] = s1[0] != s2[0];

    // fill the rest of the table
    for (int r = 1; r <= l1; ++r)
    {
        for (int c = 1; c <= l2; ++c)
        {
            if (r == 1 && c == 1) continue;

            int add = table[r][c - 1] + 1;      // left
            int remove = table[r - 1][c] + 1;   // top
            int change = table[r - 1][c - 1];   // top-left
            if (s1[r - 1] != s2[c - 1])
            {
                change++;
            }
            table[r][c] = min(add, min(remove, change));
        }
    }

    // save answer
    int answer = table[l1][l2];

    // free the table
    for (int i = 0; i < l1 + 1; ++i)
    {
        free(table[i]);
    }
    free(table);

    return answer;
}

void dump_table(int **table, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%i ", table[i][j]);
        }
        printf("\n");
    }
}

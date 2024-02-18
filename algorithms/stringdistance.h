#pragma once

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

// Weight - Fisher algorithm
int calculate_string_distance(const char *s1, const char *s2);

void dump_table(int **table, int n, int m);
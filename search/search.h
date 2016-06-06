#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void naive(char *pattern, int patternSize, char *input, int inputSize);
int max(int a, int b);
int last(char c, char *pattern, int patternSize);
void boyerMoore(char *pattern, int patternSize, char *input, int inputSize);
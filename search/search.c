#include "search.h"

void naive(char *pattern, int patternSize, char *input, int inputSize)
{
	int i = 0, j = 0;
	for (i = 0; i < inputSize - patternSize; ++i)
	{
		for (j = 0; j < patternSize && pattern[j] == input[i + j]; ++j);
		if (j == patternSize)
			printf("The string matches at position: %d\n", i);
	}
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int last(char c, char *pattern, int patternSize)
{
	int i = 0;
	int last = 0;
	for (i = 0; i < patternSize; ++i)
		if (c == pattern[i])
			last = i;
	return last;
}

void boyerMoore(char *pattern, int patternSize, char *input, int inputSize)
{
	int i = 0, j = 0;
	int k;
	while (i <= inputSize - patternSize)
	{
		j = patternSize;
		while (j > 0 && pattern[j] == input[i + j])
			j--;
		if (j == 0)
		{
			printf("The string matches at position: %d\n", i);
			++i;
		}
		else
		{
			k = last(input[i + j], pattern, patternSize);
			i = i + max(j - k, 1);
		}
	}
}
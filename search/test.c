#include "search.h"

void main()
{
	char input[] = "000010001010001";
	char pattern[] = "0001";

	printf("String searching: \n");
	printf("Pattern: %s\nInput: %s\n", pattern, input);

	// printf("Input size: %ld\nPattern size: %ld\n", strlen(input), strlen(pattern));
	printf("Naive algorithm: \n");
	naive(pattern, strlen(pattern), input, strlen(input));
	printf("\nBoyer-Moore algorithm: \n");
	boyerMoore(pattern, strlen(pattern), input, strlen(input));
}
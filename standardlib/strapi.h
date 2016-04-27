#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*------------------------- Remove Space ---------------------------*/
char *trimString(char *str) {
	int n = strlen(str);
	int flag = 1;
	int i, cnt = 0;
	char *res = (char *)malloc(n + 1);
	for (i = 0; i < n; ++i)
		if ( str[i] == ' ' )
			if ( flag == 0 ) {
				flag = 1;
				res[cnt++] = ' ';
			}
			else continue;
		else {
			flag = 0;
			res[cnt++] = str[i];
		}
	res[cnt++] = '\0';
	return res;
}
/*------------------------------------------------------------------*/


/*------------- Check if the letter is valid -----------------*/
int validStr(char *str, char *t) {
	int n = strlen(str);
	int i;
	for (i = 0; i < n; ++i) {
		if ( strcmp(t, "digit") && isalpha(str[i]) ) return 0;
		if ( strcmp(t, "alpha") && isdigit(str[i]) ) return 0;
	}
	return 1;
}
/*------------------------------------------------------------------*/

/*---------------------------- Reform ------------------------------*/
char *reformStr (char *str) {
	int n = strlen(str);
	char *res = (char *)malloc(n + 1);
	int i;
	int flag = 1;
	for (i = 0; i < n; ++i)
		if ( str[i] != ' ' ) {
			if ( flag == 1 && (int)str[i] >= (int)'a' ) {
				res[i] = str[i] ^ ' ';
			}
			else if ( flag == 0 && (int)str[i] < (int)'a' )
				res[i] = str[i] ^ ' ';
			else res[i] = str[i];
			flag = 0;
		}
		else {
			flag = 1;
			res[i] = str[i];
		}
	res[n] = '\0';
	return res;
}
/*------------------------------------------------------------------*/

/*--------------------------Split string ---------------------------*/
char **strsplit(const char* str, const char* delim, size_t* numtokens) {
	char *s = strdup(str);
	size_t tokens_alloc = 1;
	size_t tokens_used = 0;
	char **tokens = calloc(tokens_alloc, sizeof(char*));
	char *token, *strtok_ctx;
	for (token = strtok_r(s, delim, &strtok_ctx);
	        token != NULL;
	        token = strtok_r(NULL, delim, &strtok_ctx)) {
		if (tokens_used == tokens_alloc) {
			tokens_alloc *= 2;
			tokens = realloc(tokens, tokens_alloc * sizeof(char*));
		}
		tokens[tokens_used++] = strdup(token);
	}
	if (tokens_used == 0) {
		free(tokens);
		tokens = NULL;
	} else {
		tokens = realloc(tokens, tokens_used * sizeof(char*));
	}
	*numtokens = tokens_used;
	free(s);
	return tokens;
}
/* ----------------------------------------------------------------*/
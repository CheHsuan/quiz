#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_LENGTH 30

char smallest_character(char str[], char c)
{
	for(int i = 0; i < strlen(str); i++){
		if((str[i] - c) > 0)
			return str[i];
	}
	return str[0];
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char *token1, *token2;
	char *delim = " \t\n";
	char buffer[MAX_ARRAY_LENGTH];

	if((fp = fopen(argv[1], "r")) == NULL){
		printf("can't not open the file\n");
		return -1;
	}

	while(fgets(buffer, sizeof(buffer), fp) != NULL){
		token1 = strtok(buffer,delim);
		token2 = strtok(NULL, delim);
		printf("%c\n",smallest_character(token1, *token2));
	}
    return 0;
}

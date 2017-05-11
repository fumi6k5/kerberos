#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 2000

int main(int argc, char *argv[]){
	FILE *fin;
	char str[MAX], str_low[MAX], str_in[64], *sp;
	int line = 1, i;

	if(argc < 3){
		fprintf(stderr, "Error: No File Name or String.\n");
		exit(1);
	}

	if((fin = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Error: File Not Found.\n");
		exit(1);
	}

	strcpy(str_in, argv[2]);
	for(i = 0; str_in[i] != '\0'; i++)
		str_in[i] = tolower(str_in[i]);

	while(fgets(str, MAX, fin) != NULL){
		for(i = 0; str[i] != '\0'; i++){
			str_low[i] = tolower(str[i]);
		}
		if((sp = strstr(str_low, str_in)) != NULL)
			printf("%5d: %s\n", line, str);
		line++;
	}

	fclose(fin);
}

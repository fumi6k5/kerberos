#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000

int main(int argc, char *argv[]){
	FILE *fin;
	char str[MAX], *sp;
	int line = 1;

	if(argc < 2){
		fprintf(stderr, "Error: No File Name.\n");
		exit(1);
	}

	if((fin = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Error: File Not Found.\n");
		exit(1);
	}

	while(fgets(str, MAX, fin) != NULL)
		printf("%s", str);

	fclose(fin);
}

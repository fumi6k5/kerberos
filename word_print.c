#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *fin;
  char c;
  int flag = 1;
  if(argc < 2){
    fprintf(stderr, "Error: No File Name.\n");
    exit(1);
  }

  if((fin = fopen(argv[1], "r")) == NULL){
    fprintf(stderr, "Error: File Not Found.\n");
    exit(1);
  }

  while((c = fgetc(fin)) != EOF){
    if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c == '\'')){
      printf("%c", c);
      flag = 0;
    }
    else if(!flag){
      printf("\n");
      flag = 1;
    }
  }
  fclose(fin);
}

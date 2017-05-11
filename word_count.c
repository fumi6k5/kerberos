#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_MAX 1024
#define WORD_MAX 64

struct list{
  char word[64];
  int count;
  struct list *next;
};

struct list *word_list = NULL;

int count_word(char *s);
void add_list(char *s);
void show_list();

int main(int argc, char *argv[]){
  FILE *fin;
  char temp_word[WORD_MAX], c;
  int i = 0, flag = 1;

  if(argc < 2){
    fprintf(stderr, "Error: No File Name\n");
    exit(1);
  }

  if((fin = fopen(argv[1], "r")) == NULL){
    fprintf(stderr, "Error: File Not Found\n");
    exit(1);
  }

  while((c = fgetc(fin)) != EOF){
    if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c == '\'')){
      temp_word[i] = c; //1文字ずつ代入
      i++;
      flag = 0;
    }
    else if(!flag){
      temp_word[i] = '\0'; //終端文字を代入
      for(i=0; temp_word[i] != '\0'; i++)
        temp_word[i] = tolower(temp_word[i]); //小文字に変換
      if(count_word(temp_word))
        add_list(temp_word);

      i = 0;
      flag = 1;
    }
  }

  show_list();
  fclose(fin);
}

int count_word(char *s){
  struct list *temp;
  for(temp = word_list; temp != NULL; temp = temp->next){
    if(strcmp(s, temp->word) == 0){ //一致する単語があったら
      temp->count++;
      return 0;
    }
  }
  return 1;
}

void add_list(char *s){
  struct list *temp;
  temp = (struct list *)malloc(sizeof(struct list));  //メモリの動的確保
  strcpy(temp->word, s);  //単語を格納
  temp->count = 1;  //カウントをセット
  temp->next = NULL;

  if(word_list != NULL)
    temp->next = word_list;
  word_list = temp;
}

void show_list(){
  struct list *temp;
  for(temp = word_list; temp != NULL; temp = temp->next)
    printf("%3d回: %s\n", temp->count, temp->word);
}

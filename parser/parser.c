#include "parser.h"

char **parser(char *line){
  int length = strlen(line);
  char **tokens = (char **)malloc(sizeof(char *) *8);

  char *copy = (char * ) malloc (length);

  strncpy(token, line, length);
  if(tokens){
    int counter = 0;
    while(copy != NULL){
      tokens[counter] = (char *)malloc(strlen(copy));
      strcpy(tokens[counter], strsep(&copy, " "));
      counter++;

    }
  }
  free(copy);
  return tokens;
}

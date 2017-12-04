#include "aria_sh.h"
int aria_sh(){
  //run readline() to get input string from stdin
  char *line = readline();
  //parse line into tokens that repreent arguments
  char **commands = parser(line);
  //execute the builtin commands
  builtin(commands);
  //execute the commands
  exec(commands);
  return 0;
}


//when given a set of commands, checks if the commands are the builtin commands
void builtin(char ** commands){ //CD and EXIT
  //if command  == cd
  if(strcmp(commands[0], "cd") == 0){
    chdir(commands[1]);

  } else if(strcmp(commands[0], "exit") == 0){
    //if command == exit
    exit(0);
    printf("Aria has exited");
  }
}


char *readline(){
  //stores input froms tdin to character string pointer

  //allocating memory to line
  char *line = malloc(256);
  //reading sizeof(char)*1024 bytes of data from stdin to line
  fgets(line, 256 , stdin);
  int length = strlen(line); // check line length

  //if the end of line is a \n then replace it with a null terminator
  if(length > 0 && line[length-1] == '\n'){
      line[length -1 ] = '\0';
  }
  //return
  return line;
}

void sighandler(int signumber){
  if(signumber == SIGINT){
    //if bash still running then aria_sh()
    printf("\n>");
    aria_sh();
    fflush(stdout);
  }
}

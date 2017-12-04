#include "exec.h"

int exec(char** args){
  char ** cmds
  char ** bcmds;
  int cmdlength, restlength;
  for(cmdlength = 0 ; args[cmdlength]; cmdlength+=1){}

  int i;
  for(i = 0; args[i]; i++){
    int type = token(args[i]);
    //if the token is ;
    if(type == 1){
      restlength = cmdlength-i-1;
      cmds= malloc(i*8);
      bcmds = malloc(restlength*8);
      memcpy(cmds, args, i*8);
      memcpy(bcmds, args+i+1, restlength*8);
      if(fork()==0){
        execvp(cmds[0],cmds);
        exit(0);
      } else {
        wait(0);
        printf("n");
        free(cmds);
        exec(bcmds);
      }
      return 0;
    } else if (type == 2 ) {
      //if the token is >
      restlength = cmdlength-i-2;

      int pipefd[2];
      int pid;

      cmds = malloc(i*8);
      memcpy(cmds, args, i);
      memcpy(bcmds, args+i+1, restlength *8);

      char **cmdsright;

      i++;
      restlength = cmdlength-i-1;

      cmdsright = malloc(i*8);
      memcpy(cmdsright, args, (i-1) * 8);

      pipe(pipefd);
      pid = fork();
      if(fork() == 0){
        dup2(pipefd[0],0);
        close(pipefd[1]);
        execvp(cmdsright[0], cmdsrights);
      } else{
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        execvp(cmds[0],,cmds);
      }
      free(cmds);
      free(cmdsright);
      return 0;
    } else if (type == 3){
      //if token is <
      restlength = cmdlength -i-1;
      return 0;
    } else if (type == 4){
      //if token is |
      restlength = cmdlength-i-1;
      return 0;
    }

  }
  if(fork() == 0){
    execvp(args[0], args);
    exit(0);
  } else {
    wait(0);
  }
  return 0;
}

int token(char * token){
  if (strchr(token, ';')) return 1;
    else if (strpbrk(token, ">>")) return 22;
    else if (strchr(token, '>')) return 2;
    else if (strpbrk(token, "<<")) return 33;
    else if (strchr(token, '<')) return 3;
    else if (strchr(token, '|')) return 4;
    else return 0;
}

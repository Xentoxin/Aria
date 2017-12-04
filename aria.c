#include "aria.h"
int main(){
  signal(SIGINT, &sighandler);
  signal(SIGSTP, &sighandler);
  while(1){
    printf(">");
    aria_sh();
  }
  return 0;
}

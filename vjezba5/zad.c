#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define ERR_COMMAND 15

int check_child(int s){
  int n;
  if(WIFEXITED(s)){
    n=WEXITSTATUS(s);
    printf("Child exit status: %d\n",n);
  }else if(WIFSIGNALED(s)){
    n=WTERMSIG(s);
    printf("Child term signal: %d\n",n);
  }else{
    n=WSTOPSIG(s);
    printf("Child stop signal: %d\n",n);
  }
  
  return n;
}

int main(int argc, char **argv) {

if(argc<2){
  printf("Koristenje: ./zad <naredba> [argument] ..\n");
  return 0;
}

int pid = fork();
if(pid < 0){
  perror("fork");
  return -1;
}else if(pid == 0){
  execvp(argv[1], &argv[1]);
  perror("execvp");
  return ERR_COMMAND;
}else{
  int st;
  wait(&st);
  if(check_child(st) == ERR_COMMAND){
    printf("Nepostojeca naredba\n");// error handling
  }
}
return 0;
}
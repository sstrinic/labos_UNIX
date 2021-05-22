#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define ERR_COMMAND 15
#define ERR_FILE 20

#define PRAVA S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH

int s;
int chld_running = 1;

void chld_handler(int signo){

  wait(&s);
  //printf("\n sig_chld done\n");
  chld_running = 0;
}

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

if(argc<3){
  printf("Koristenje: %s <datoteka>  <naredba> [argument] ..\n", argv[0]);
  return 0;
}

int pid = fork();
if(pid < 0){
  perror("fork");
  return -1;
}else if(pid == 0){
  
  int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, PRAVA);
  if(fd < 0){
    perror("open");
    exit(ERR_FILE);
    }
  dup2(fd, STDOUT_FILENO);
  if(fd != STDOUT_FILENO)
    close(fd);
  
  execvp(argv[2], &argv[2]);
  perror("execvp");
  return ERR_COMMAND;
}else{
  //int s;
  //wait(&s);
  signal(SIGCHLD, chld_handler);
  int k = 0;
  while(chld_running){
    k++;
    sleep(1);
  }
  if(check_child(s) == ERR_COMMAND){
    printf("Nepostojeca naredba\n");// error handling
  }
  printf("Trajanje childa: %ds\n",k);
}
return 0;
}
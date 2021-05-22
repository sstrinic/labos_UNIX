#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

if(fork() == 0){
  if(fork() == 0){
    sleep(3);
    printf("CHILD 2 - pid: %d\t ppid: %d\t uid: %d\n", getpid(), getppid(), getuid());
  }else{
    printf("CHILD 1 - pid: %d\t ppid: %d\t uid: %d\n", getpid(), getppid(), getuid());
    return 0;
  }
}else{
  wait(NULL);
  printf("PARENT 1 - pid: %d\t ppid: %d\t uid: %d\n", getpid(), getppid(), getuid());
}
sleep(5);
return 0;
}
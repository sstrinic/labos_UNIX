#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

int n;
char c;
while((n=read(STDIN_FILENO,&c,1))>0)
  write(STDOUT_FILENO,&c,1);

return 0;
}
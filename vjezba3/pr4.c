#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fn.h"

int main(int argc, char *argv[]){

int fd,k;

if(argc<2){
  rw(STDIN_FILENO, STDOUT_FILENO);
  
}else{
  for(k=1;k<argc;k++){
    fd=open(argv[k],O_RDONLY);
    if(fd== -1){
      perror("open");
      return -1;
    }
    rw(fd,STDOUT_FILENO);
    close(fd);
  }
}
 
return 0;
}
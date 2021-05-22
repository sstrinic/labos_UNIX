#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int rw(int fdin, int fdout){
  int n;
  char c;
  while((n=read(fdin,&c,1))>0)
    write(fdout,&c,1);
  
  if(n < 0)
    perror("read");
    
  return n;
}
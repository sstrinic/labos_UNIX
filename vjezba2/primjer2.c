#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
int fd,n,i;
char sl;

if(argc<2){
  printf("Koristenje: primjer2 <ime_dat> [ime_dat] ...\n");
  exit(0);
}

for(i=1;i<argc;i++)
{
fd=open(argv[i],O_RDONLY);
if(fd<0){
  perror("open");
  }
while((n=read(fd,&sl,1))>0){
  write(STDOUT_FILENO,&sl,1);
}
if(n== -1){
  perror("read");
  }
close(fd);
}

return 0;
}
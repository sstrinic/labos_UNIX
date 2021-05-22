#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void Info();

int main(int argc, char *argv[])
{
  pid_t pid;
  
  pid = fork();
  if(pid == -1)	
  {
      perror("fork");
      return -1;  
  }  
  else if(pid > 0)
  {
      wait(NULL);
      printf("PARENT");
      Info();
  }
  else
  {
      printf("CHILD");			
      Info();
  }
    
  return 0;
}

void Info()
{
  printf("\n########\n");
  printf("Process ID: %d\n", getpid());
  printf("Parent process ID: %d\n", getppid());
  printf("User ID: %d\n", getuid());
}
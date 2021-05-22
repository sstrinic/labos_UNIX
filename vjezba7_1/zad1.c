#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

char* form_date(time_t val,char* str){
  strftime(str, 36, "%b %d %H:%M", localtime(&val));
  return str;
}

void print_info(struct stat buf){
    printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
    printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
    printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
    printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
    printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
    printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
    printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
    printf( (buf.st_mode & S_IROTH) ? "r" : "-");
    printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
    printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
}

int main(int argc, char **argv){
  DIR *dp;
  struct dirent *de;
  struct stat buf;
  char fname[512];
  char date[36];
  
  if(argc == 1){
    dp = opendir(".");
    if(dp == NULL){ 
    perror("opendir"); 
    return 0;
    }
	while((de = readdir(dp)) != NULL){
        if(argc == 1)
          argv[1] = ".";
        sprintf(fname, "%s/%s", argv[1], de->d_name);
        if(lstat(fname, &buf) < 0){
          perror("lstat");
        }
        print_info(buf);
        printf(" %d %d %d %d \t %s \t %s \n",(int)buf.st_nlink,buf.st_uid,buf.st_gid,(int)buf.st_size,form_date(buf.st_mtime,date),de->d_name);
      }
    closedir(dp);
  }else{
    if(lstat(argv[1],&buf) < 0){
      perror("lstat");
      return 0;
    }
   if(S_ISREG(buf.st_mode)){
     print_info(buf);
     printf(" %d %d %d %d \t %s \t %s \n",(int)buf.st_nlink,buf.st_uid,buf.st_gid,(int)buf.st_size,form_date(buf.st_mtime,date),argv[1]);
   }else{
      dp = opendir(argv[1]);
      while((de = readdir(dp)) != NULL){
        if(argc == 1)
          argv[1] = ".";
        sprintf(fname, "%s/%s", argv[1], de->d_name);
        if(lstat(fname, &buf) < 0){
          perror("lstat");
        }
        print_info(buf);
        printf(" %d %d %d %d \t %s \t %s \n",(int)buf.st_nlink,buf.st_uid,buf.st_gid,(int)buf.st_size,form_date(buf.st_mtime,date),de->d_name);
      }
      closedir(dp);
    }
  }
  
  return 0;
}
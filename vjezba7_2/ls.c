#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <string.h>

char* form_date(time_t val,char* str){
  strftime(str, 36, "%b %d %H:%M", localtime(&val));
  return str;
}

char* print_file_info(struct stat buf, char* stra){
    strcat(stra,((S_ISDIR(buf.st_mode)) ? "d" : "-"));
    strcat(stra,((buf.st_mode & S_IRUSR) ? "r" : "-"));
    strcat(stra,((buf.st_mode & S_IWUSR) ? "w" : "-"));
    strcat(stra,((buf.st_mode & S_IXUSR) ? "x" : "-"));
    strcat(stra,((buf.st_mode & S_IRGRP) ? "r" : "-"));
    strcat(stra,((buf.st_mode & S_IWGRP) ? "w" : "-"));
    strcat(stra,((buf.st_mode & S_IXGRP) ? "x" : "-"));
    strcat(stra,((buf.st_mode & S_IROTH) ? "r" : "-"));
    strcat(stra,((buf.st_mode & S_IWOTH) ? "w" : "-"));
    strcat(stra,((buf.st_mode & S_IXOTH) ? "x" : "-"));
    return stra;
}

void print_info(struct dirent *de, struct stat buf, char fname[], int argc, char *argv[], DIR *dp, char date[]) {
    struct files{
      char name[30];
      char dat[1024];
    }file[100],tmp;
    int i=0;
    int j,k,z;
    char stra[20];    
    while ((de = readdir(dp)) != NULL) {
        if (argc == 1)
            argv[1] = ".";
        sprintf(fname, "%s/%s", argv[1], de->d_name);
        if (lstat(fname, &buf) < 0) {
            perror("lstat");
        }
        sprintf(file[i].dat, " %s  %d %d %d %d \t %s \t %s ", print_file_info(buf,stra), (int)buf.st_nlink, buf.st_uid, buf.st_gid, (int)buf.st_size, form_date(buf.st_mtime, date), de->d_name);
        sprintf(file[i].name, "%s", de->d_name);
        i++;
        strcpy(stra,"\0");
    }
    
    for(j=0; j<i-1; j++){
      for(k=j+1; k<i; k++){
        if(strcmp(file[j].name, file[k].name) > 0){
          tmp = file[j];
          file[j] = file[k];
          file[k] = tmp;
        }
      }  
    }
    
    for(z=0; z<i; z++)
      printf("%s\n",file[z].dat);
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
    print_info(de, buf, fname, argc, argv, dp, date);
    closedir(dp);
  }else{
    if(lstat(argv[1],&buf) < 0){
      perror("lstat");
      return 0;
    }
   if(S_ISREG(buf.st_mode)){
     char str[20];
     printf(" %s %d %d %d %d \t %s \t %s \n",print_file_info(buf,str), (int)buf.st_nlink, buf.st_uid,buf.st_gid,(int)buf.st_size, form_date(buf.st_mtime,date), argv[1]);
   }else{
      dp = opendir(argv[1]);
      print_info(de, buf, fname, argc, argv, dp, date);
      closedir(dp);
    }
  }
  
  return 0;
}
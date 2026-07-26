
#include "search.h"



int main(){
char *input;
char path[256];
char line[1024];
banner(); 

  input=readline("name of file : ");
 
  pid_t pid =search(input);


  printf(GREEN"file name : %c\n"RESET,input);


  // read cmdline :
  snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
  FILE *fd= fopen(path,"r");
 
if (fd == NULL)
{
    perror("fopen");
    return 1;
} 
  size_t len = fread(line, 1, sizeof(line) , fd);
  for (size_t i = 0; i < len; i++)
  {
    if (line[i] == '\0')
        line[i] = ' ';
    }
  line[len] = '\0';

  printf(BLUE"the command used to lunch %s is  : %s\n"RESET, input ,line);

  fclose(fd);
  line[0]='\0';
  len =0;

// read  status :
  snprintf(path,sizeof(path),"/proc/%d/status",pid);
    fd= fopen(path,"r");

if (fd == NULL)
{
    perror("fopen");
    return 1;
}

    while (fgets(line, sizeof(line), fd) != NULL){
        if (strncmp(line,"State:",6)==0||
            strncmp(line,"Pid:",4)==0||
            strncmp(line,"PPid:",5)==0||
            strncmp(line,"Threads:",8)==0||
            strncmp(line,"VmSize:",7)==0||
            strncmp(line,"VmRSS:",6)==0 ){

         printf(BLUE"-%s\n"RESET,line);
        }
    }

  fclose(fd);
  line[0]='\0';
  path[0]='\0';


 // read executable form exe :
    snprintf(path,sizeof(path),"/proc/%d/exe",pid);
    
     len = readlink(path, line, sizeof(line) - 1);
    
    line[len+1]='\0';
    
    printf(BLUE"Executable : %s\n"RESET,line);
      
    line[0]='\0';
    len =0;


    
 
 // read current working directory (cwd)
   line[0] = '\0';
   snprintf(path, sizeof(path), "/proc/%d/cwd", pid);

   len = readlink(path, line, sizeof(line) - 1);

  if (len != -1)
   {
     line[len] = '\0';
     printf(GREEN"Current Working Directory : %s\n"RESET, line);
   }

   line[0] = '\0';


  // read root directory (root)
  snprintf(path, sizeof(path), "/proc/%d/root", pid);

  len = readlink(path, line, sizeof(line) - 1);

  if (len != -1)
   {
    line[len] = '\0';
    printf(GREEN"Root Directory : %s\n"RESET, line);
   }

   line[0] = '\0';
    return 0;

}
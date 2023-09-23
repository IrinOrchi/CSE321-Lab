#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


int main(int argc,char *argv[])
{ 
  int f;
  FILE *f1;
   f=open("file.txt",O_RDWR); 
   close(f);
   f1=fopen("file.txt","w"); 
    
    for (int i=1;i<argc;i++){
    int t=atoi(argv[i]);
      
    if (t==-1){
        fclose(f1);
        break;
    }
    else{
    
      fputs(argv[i],f1);
      fputs("\n",f1);
      
        }
      }
      
      fclose(f1);
   
  return 0;
    
}

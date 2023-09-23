#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


int main(int argc,char *argv[])
{  
  if (argc <2){
        printf("No command line arguments found.\n"); 
    }
  else{
    printf("The numbers:\n");
    for (int i=1;i<argc;i++){
    int t=atoi(argv[i]);
      if(t%2==0)
      {
        printf("%d is Even\n",t);
      }
      else{
        printf("%d is Odd\n",t);
      }
   
      }
    }
  return 0;
    
}

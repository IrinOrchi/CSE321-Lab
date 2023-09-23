#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t a,b,c,d,e,f;
    int count=0;
   
    for(int i=0;i<3;i++)
      {
          a=fork();
          count++;
          if(getpid()%2!=0)
          {
               d=fork();
               count++;
         
            
          }
        
      }

      for(int i=0;i<3;i++)
      {
          b=fork();
          count++;
          if(getpid()%2!=0)
          {
               e=fork();
               count++;
         
            
          }
        
      }
      for(int i=0;i<3;i++)
      {
          c=fork();
          count++;
          if(getpid()%2!=0)
          {
              f=fork();
               count++;
         
            
          }
        
      }

  
  
         
    printf("%d\n",count);
    return 0;
}


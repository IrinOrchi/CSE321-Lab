#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t pid, pid1;
	pid = fork();
  if(pid<0)
  {
    printf("Error\n");
  }
	else if (pid == 0) {
		sleep(2);
		printf("I am child \n");
	}

	else {
		   pid1 = fork();
       if(pid<0)
       {
        printf("Error\n");
       }
		   else if (pid1 == 0) {
			    sleep(1);
			    printf("I am grandchild \n");
		      }
       
       else{
           sleep(3);
	        printf("I am parent\n ");
         }     	
    }
	return 0;
}

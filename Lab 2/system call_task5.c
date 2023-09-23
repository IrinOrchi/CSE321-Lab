#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>


int main()
{
	pid_t pid, pid1, pid2,pid3;
	pid = fork();
  if(pid<0)
  {
    printf("Error\n");
  }
	else if (pid == 0) {
		sleep(2);
		printf("2. Child process ID : = %d \n",getpid());
	}

	else {
		   pid1 = fork();
       if(pid1<0)
       {
          printf("Error\n");
       }
    
		   else if (pid1 == 0) {
			    sleep(3);
			    printf("3. Grand Child process ID : %d \n",getpid());
		   }
		   else {
			      pid2 = fork();
            if(pid2<0)
             {
                printf("Error\n");
             }
			      else if (pid2 == 0) {
              sleep(4);
				      printf("4. Grand Child process ID : %d \n",getpid());
			       }
			       else {
			            pid3 = fork();
                  if(pid3<0)
                  {
                   printf("Error\n");
                  }
			            else if (pid3 == 0) {
                     sleep(5);
				             printf("5.Grand Child process ID : %d \n",getpid());
			            }
                  else {
                    sleep(1);
				            printf("1. Parent process ID: %d\n", getpid());
			            }
		           }
          	}
	        }

	return 0;
}

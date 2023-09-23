#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>


void *func_thread(int *n);


int main(){
	pthread_t t1;
  pthread_t t2;
  pthread_t t3;
  pthread_t t4;
  pthread_t t5;

  int v1=1;
  int v2=2;
  int v3=3;
  int v4=4;
  int v5=5;


  pthread_create(&t1,NULL,(void *)func_thread,&v1);
  pthread_join(t1, NULL);
  printf("thread-%d closed\n",v1);


  pthread_create(&t2,NULL,(void *)func_thread,&v2);
  pthread_join(t2, NULL);
  
  printf("thread-%d closed\n",v2);

  pthread_create(&t3,NULL,(void *)func_thread,&v3);
  pthread_join(t3, NULL);
  printf("thread-%d closed\n",v3);

  pthread_create(&t4,NULL,(void *)func_thread,&v4);
  pthread_join(t4, NULL);
  printf("thread-%d closed\n",v4);


  pthread_create(&t5,NULL,(void *)func_thread,&v5);
  pthread_join(t5, NULL);
  printf("thread-%d closed\n",v5);

  return 0;
 }
  
void *func_thread(int *n){
   printf("thread-%d is running\n",*n);
}



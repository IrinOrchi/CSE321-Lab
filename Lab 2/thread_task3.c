#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>


int count_ASKI();
int *func_thread();
int *func_thread1();

int main(){
  long r1;
  long r2;
  long r3;
	pthread_t t1;
  pthread_t t2;
  pthread_t t3;

  pthread_t t4;

 
  pthread_create(&t1,NULL,(void *)func_thread,NULL);
  r1=count_ASKI();
  pthread_join(t1, NULL);
  

  pthread_create(&t2,NULL,(void *)func_thread,NULL);
  r2=count_ASKI();
  pthread_join(t2, NULL);
  
  

  pthread_create(&t3,NULL,(void *)func_thread,NULL);
  r3=count_ASKI();
  pthread_join(t3, NULL);

  if(r1==r2 && r2==r3 )
  {
      printf("Youreka");
    
  }
  else if(r1==r2 ){

     printf("Miracle");
  }
  else if(r1==r3 ){

     printf("Miracle");
  }
 else if(r2==r3 ){

     printf("Miracle");
  }

 else{
  pthread_create(&t4,NULL,(void *)func_thread1,NULL);
  pthread_join(t4, NULL);
   
 }
 

  return 0;
 }
  
int *func_thread(){
   
    pthread_exit(NULL);
  }

int *func_thread1(){
 
    printf("Hasta la vista");
    pthread_exit(NULL);
    
  }

  

int count_ASKI()
{
   char name[100];
   
   int sum=0;
   printf("Enter your name: ");
   
   scanf("%s",name);
   
   int l=strlen(name);
   for(int i=0;i<l;i++)
     {
        int d=name[i];
        sum=sum+d;
        
     }
  
   return sum;

  
}
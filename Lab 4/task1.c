#include <pthread.h>
#include <stdio.h>
#include <string.h>


#define MAX 10 //producers and consumers can produce and consume upto MAX
#define BUFLEN 7
#define NUMTHREAD 2 /* number of threads */


void * consumer(int *id);
void * producer(int *id);

char buffer[BUFLEN];
char source[BUFLEN]; //from this array producer will store it's production into buffer
int pCount = 0;
int cCount = 0;
int buflen;

int in=0;
int out=0;

//initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;

int thread_id[NUMTHREAD] = {0,1};
int i = 0;
int j = 0;
int main()
{
int i;
/* define the type to be pthread */
pthread_t thread[NUMTHREAD];
strcpy(source,"abcdef");
buflen = strlen(source);
/* create 2 threads*/
/* create one consumer and one producer */
/* define the properties of multi threads for both threads */
//Write Code Here

  pthread_t pro,con;
  pthread_mutex_init(&count_mutex, NULL);
  pthread_cond_init(&nonEmpty, NULL);
  pthread_cond_init(&full, NULL);
  
 
  
  pthread_create(&pro, NULL, (void *)producer,&thread_id[0]);
  pthread_create(&con, NULL, (void *)consumer, &thread_id[1]);
    
  
  pthread_join(pro, NULL);
  pthread_join(con, NULL);
   

  pthread_mutex_destroy(&count_mutex);
  pthread_cond_destroy(&nonEmpty);
  pthread_cond_destroy(&full);
 

  return 0;
}
void * producer(int *id)
{
/*
1. Producer stores the values in the buffer (Here copies values from source[] to buffer[]).
2. Use mutex and thread communication (wait(), sleep() etc.) for the critical section.
3. Print which producer is storing which values using which thread inside the critical
section.
4. Producer can produce up to MAX
*/
//Write code here

for(int i = 0; i < MAX; i++) {
  
    pthread_mutex_lock(&count_mutex);
    if(in==BUFLEN ){
    pthread_cond_wait(&nonEmpty,&count_mutex);
      }
    buffer[in] = source[in];
    printf("%d Produced %c by Thread  %d\n", pCount,buffer[in],*((int *)id));
    pCount=pCount+1;
    in = (in+1)%BUFLEN;
    pthread_mutex_unlock(&count_mutex);
    pthread_cond_signal(&full);
  
    }
 
}
void * consumer(int *id)
{
/*
1. Consumer takes out the value from the buffer and makes it empty.
2. Use mutex and thread communication (wait(), sleep() etc.) for critical section
3. Print which consumer is taking which values using which thread inside the critical
section.
4. Consumer can consume up to MAX
*/
//Write code here


for(int i = 0; i <MAX ; i++) {
  
    pthread_mutex_lock(&count_mutex);
    if(in==0 ){
    pthread_cond_wait(&full,&count_mutex);
      }
    buffer[out] = source[out];
    printf("%d consumed %c by Thread  %d\n",cCount,buffer[out],*((int *)id));
    cCount=cCount+1;
    out = (out+1)%BUFLEN;
    pthread_mutex_unlock(&count_mutex);
    pthread_cond_signal(&nonEmpty);
    
       
    }
}
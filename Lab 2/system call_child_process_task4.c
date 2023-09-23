#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{   
     int a[10];
     int maxIndex = 0, minIndex =0;
     int temp=0;
     pid_t p;
     
     if (argc <2)
     {
         printf("No command line arguments found.\n");  
         
     }
     else
     { 

       for (int i = 0; i < 10; i++){
              a[i] = atoi(argv[1+ i]);
            }
       p=fork();
       if(p<0){
         printf("Error\n");
       }
       else if(p==0)
       {
            for(int i = 0 ; i < 10 ; i++ )
                {
                        for(int j = 0 ; j < 10-i-1 ; j++)
                        {
                                if(a[j] < a[j+1])
                                {
                                        temp = a[j];
                                        a[j] = a[j+1];
                                        a[j+1] = temp;
                                }
                        }
                }
                printf("The sorted elements:\n");
                for(int i = 0 ; i < 10 ; i++)
                {
                        printf("%d \n",a[i]);
                }
                printf("\n");
            
       }

       else{
         sleep(1);
          printf("The ODD or EVEN numbers:\n");
          for(int i = 0 ; i < 10 ; i++ )
                {
                      if(a[i]%2==0)
                      {
                        printf("%d is EVEN\n",a[i]);
                      }
                      else{
                        printf("%d is ODD\n",a[i]);
                      }

                  
                }
         

         
       }
       }
     return 0;
   
    
}

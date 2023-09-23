#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    
     int a[10];
     int maxIndex = 0, minIndex =0;
     int temp=0;

     
     if (argc <2)
     {
         printf("No command line arguments found.\n");  
         
     }
     else
     {     for (int i = 0; i < 10; i++){
              a[i] = atoi(argv[1+ i]);
            }
         
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
            
       }
     return 0;
}

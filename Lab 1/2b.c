#include<stdio.h>
#include<string.h>
#include <stdlib.h>


void main()
{
    FILE* f;
    FILE* f1;
    char ch[100];
    f = fopen("2b_input.txt", "r");
 
    if (f == NULL) {
        printf("file can't be opened \n");
    }
 
   
    while (!feof(f)) {
        fgets(ch,100,f);
        
    }
   
    int l=strlen(ch);

    char reduce[l];
    
    int i=0;
    int j=0;
    
    while(ch[i]!='\0')
    {
       if(!(ch[i]==' ' && ch[i+1]==' '))
       {
              reduce[j]=ch[i];
              j++;
       }
       i++;
    }
    reduce[j]='\0';
    //printf("%s", reduce);


    fclose(f);

    f1 = fopen("2b_output.txt", "w");

    if (f == NULL) {
        printf("file does not exist \n");
    }
    fputs(reduce,f1);
    fclose(f1);


    
}

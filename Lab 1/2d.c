#include<stdio.h>
#include<string.h>
#include <stdlib.h>


void main()
{
    FILE* f;
    void isupdate(char *string);
    char ch[100];
    f = fopen("2d_input.txt", "r");
 
    if (f == NULL) {
        printf("file can't be opened \n");
    }
 
   
    while (!feof(f)) {
        fgets(ch,100,f);
       
        isupdate(ch);
        
    }
    fclose(f);
}

void  isupdate(char *string){
    char *ret;
    
    ret = strstr(string, "@sheba.xyz");
    if (ret)
        printf("Email address is okay\n");
    else
        printf("Email address is outdated\n");

    
}
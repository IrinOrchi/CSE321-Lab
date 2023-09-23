#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include <stdlib.h>

void main()
{
    FILE* f;
    void varify_password(char *p);
    void isPalindrome(char* string);
    char ch[100];
    f = fopen("2c_input.txt", "r");
 
    if (f == NULL) {
        printf("file can't be opened \n");
    }
 
   
    while (!feof(f)) {
        fgets(ch,100,f);
       // printf("%s",ch);
        varify_password(ch);
        
        
    }
    fclose(f);
}
void varify_password(char *p)
{  
   int l=strlen(p);
   char s[]={'_' ,'$','#','@'};
   int t=strlen(s);
   bool has_upper=false;
   bool has_lower=false;
   bool has_digit=false;
   bool has_sc=false;

   for(int i=0;i<l;i++)
   {
   
    if(isupper(p[i]))
    {
      has_upper=true;  
    }
    
    
    if(islower(p[i]))
    {
      has_lower=true;  
    }
    
    if(isdigit(p[i]))
    {
      has_digit=true;  
    }
   
   for(int j=0;j<t;j++)
   {
      if(p[i]==s[j])
      {
         has_sc=true; 
      }

    }
   }
 if(has_upper==true && has_lower==true && has_digit== true && has_sc==true)
 {
    printf("OK\n");
 }
if(has_upper==false && has_lower==true && has_digit== true && has_sc==true)
 {
    printf("Upper character missing\n");
 }
 if(has_upper==true && has_lower==false && has_digit== true && has_sc==true)
 {
    printf("Lower character missing\n");
 }
 if(has_upper==true && has_lower==true && has_digit== false && has_sc==true)
 {
    printf("Digit missing\n");
 }
 if(has_upper==true && has_lower==true && has_digit== true && has_sc==false)
 {
    printf("Special character missing\n");
 }

 if(has_upper==false && has_lower==false && has_digit== true && has_sc==true)
 {
    printf("Upper character missing, Lower character missing\n");

 }
 if(has_upper==false && has_lower==true && has_digit== false && has_sc==true)
 {
    printf("Upper character missing, Digit missing\n");

 }
 if(has_upper==false && has_lower==true && has_digit== true && has_sc==false)
 {
    printf("Upper character missing, Special character missing\n");

 }
 if(has_upper==true && has_lower==false && has_digit== true && has_sc==false)
 {
    printf("Lower character missing, Special character missing\n");

 }

 if(has_upper==true && has_lower==false && has_digit== false && has_sc==true)
 {
    printf("Lower character missing, Digit missing\n");

 }
 if(has_upper==true && has_lower==true && has_digit== false && has_sc==false)
 {
    printf("Digit missing, Special character missing\n");

 }
 if(has_upper==true && has_lower==false && has_digit== false && has_sc==false)
 {
    printf("Lower character missing ,Digit missing, Special character missing\n");
 }
  if(has_upper==false && has_lower==true && has_digit== false && has_sc==false)
 {
    printf("Upper character missing, Digit missing, Special character missing\n");
 }
 if(has_upper==false && has_lower==false && has_digit== true && has_sc==false)
 {
    printf("Upper character missing, Lower character missing , Special character missing\n");
 }


if(has_upper==false && has_lower==false && has_digit== false && has_sc==true)
 {
    printf("Upper character missing, Lower character missing, Digit missing\n");
 }
if(has_upper==false && has_lower==false && has_digit== false && has_sc==false)
 {
    printf("Upper character missing, Lower character missing, Digit missing, Special character missing/n");

}
 }
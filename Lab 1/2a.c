#include<stdio.h>

void main(){

   int addition(int a, int b);
   int subtraction(int a, int b);
   int multiplication(int a, int b);


   int x=0;
   int y=0;
   int result=0;
   char op;
   char temp;
   
   printf("Enter the first number: ");
   scanf("%d",&x);
   printf("Enter the second number: ");
   scanf("%d",&y);
   printf("Enter an operator('+'/'-'/'*'): ");
   scanf("%c",&temp);
   scanf("%c",&op);
   
   if(op=='+'){
    result=addition(x,y);
    printf("The result is: %d", result);
   }
   if(op=='-'){
    result=subtraction(x,y);
    printf("The result is: %d", result);
   }
   
   if(op=='*'){
    result=multiplication(x,y);
    printf("The result is: %d", result);
   }
  
}

int addition(int a,int b){
    return (a+b);
}

int subtraction(int a,int b){
    if(a>b){
     return (a-b);
    }
    else{
     return (b-a);    
    }
}

int multiplication(int a,int b){
    return (a*b);
}


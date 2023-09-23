#include<stdio.h>

struct item{
    int quantity;
    int unite_price;
};

void main(){

    struct item paratha;
    struct item vegetable;
    struct item water;
    int p;
    

    
    printf("Quantity of Paratha: ");
    scanf("%d",&paratha.quantity);
    printf("Unit Price: ");
    scanf("%d",&paratha.unite_price);
   

    printf("Quantity of Vegetable: ");
    scanf("%d",&vegetable.quantity);
    printf("Unit Price: ");
    scanf("%d",&vegetable.unite_price);
   

    printf("Quantity of Mineral Water: ");
    scanf("%d",&water.quantity);
    printf("Unit Price: ");
    scanf("%d",&water.unite_price);
    
    int total=(paratha.quantity*paratha.unite_price)+(vegetable.quantity*vegetable.unite_price)+(water.quantity*water.unite_price);
    printf("Number of People: ");
    scanf("%d",&p);
    float payment=total/p;

    
    printf("Individual people will pay: %.2f tk",payment);

    
}

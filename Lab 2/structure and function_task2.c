#include <stdio.h>
void find_perfect( int );

void main ()
{
    int S_R;
    int E_R;

    printf("Enter the starting range: ");
    scanf("%d", &S_R);
    printf("Enter the ending range: ");
    scanf("%d", &E_R);
    for (int i=S_R ; i<= E_R; i++)
    {
        find_perfect(i) ;
    }


    
}

void find_perfect(int num)
{
    int sum = 0 ;

    for (int j = 1 ; j<num; j++)
    {
        if ( num % j == 0 )
             sum += j ;
    }

    if (sum == num )
     printf (" %d \n", num) ;
}

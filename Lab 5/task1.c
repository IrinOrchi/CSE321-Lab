#include <stdio.h>
int arrmax[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, m;
void input()
{
int i, j;
printf("Enter the number of Processes\t");
scanf("%d",&n);
printf("Enter the numbers of resource instances \t");
scanf("%d",&m);
printf("Enter the Allocation Matrix\n");
for (i = 0; i<n; i++){

    for (j = 0; j<m; j++){
        scanf("%d", &alloc[i][j]);}
        }
printf("Enter the Max Matrix\n");
for (i = 0; i<n; i++){
    for (j = 0; j < m; j++){
        scanf("%d", &arrmax[i][j]);}
        }
printf("Enter the available Resources\n");
for (j = 0; j<m; j++){
    scanf("%d", &avail[j]);
    }
    }
void cal()
{


int finish[100], temp, need[100][100], flag = 1, k, c1 = 0;
int dead[100];
int safe[100];
int i, j;
for (i = 0; i<n; i++){
    finish[i] = 0;
    }
for(i=0;i<n;i++){
    for (j=0;j<m;j++){
     need[i][j]=arrmax[i][j]-alloc[i][j];
    }
}
while(flag)
{
    flag=0;
    for(i=0;i<n;i++){
      int c=0;
      for(j=0;j<m;j++){
        if ((finish[i]==0)&&(need[i][j]<=avail[j]))
        {

            c++;
            if(c==m){
                for(k=0;k<m;k++){

                    avail[k]+=alloc[i][j];
                    finish[i]=1;
                    flag=1;
                }
            }
        }
      }
    }

}
j=0;
flag=0;
for(i=0;i<n;i++){

    if (finish[i]==0){
        dead[j]=i;
        j++;
        flag=1;
    }
}
if(flag==1){
    printf("\n\nDeadlock Ahead");

}
else{
    printf("\nSafe here");
}
}

int main()
{
    int i,j;
    input();
    cal();
    return 0;
}

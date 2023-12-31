#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    n = 6; // Number of processes
    m = 4; // Number of resources
    int alloc[6][4] = { { 0, 1, 0, 3 }, // P0 // Allocation Matrix
                        { 2, 0, 0, 3 }, // P1
                        { 3, 0, 2, 0 }, // P2
                        { 2, 1, 1, 5 }, // P3
                        { 0, 0, 2, 2 }, // P4
                        { 1, 2, 3, 1 }}; // P5
 
    int max[6][4] = { { 6, 4, 3, 4 }, // P0 // MAX Matrix
                      { 3, 2, 2, 4 }, // P1
                      { 9, 1, 2, 6 }, // P2
                      { 2, 2, 2, 8 }, // P3
                      { 4, 3, 3, 7 }, // P4
                      { 6, 2, 6, 5 }}; // P5
 
    int avail[4] = { 2, 2, 2, 1 }; // Available Resources
 
    int finish[n], safe[n], count = 0;
    for (k = 0; k < n; k++) {
        finish[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    safe[count++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
   
      int flag = 1;
       
      for(int i=0;i<n;i++)
    {
      if(finish[i]==0)
      {
        flag=0;
         printf("Deadlock Ahead\n");
        break;
      }
    }
     
      if(flag==1)
    {
      printf("The safe sequence is:");
      for (i = 0; i < n - 1; i++){
        printf(" P%d -->", safe[i]);
      }
      printf(" P%d", safe[n - 1]);
    }
     
 
    return (0);
 
    
}
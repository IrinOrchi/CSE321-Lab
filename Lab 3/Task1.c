#include<stdio.h>
struct process
{
    int pid,AT,BT,CT,TAT,WT;
};

struct process P[10];

int main()
{
    int n=0,temp[10];
    int count=0,S_P=0;
   
    printf("Enter the number of the process: ");
    scanf("%d",&n);
    printf("Enter the Arrival Time of process:\n");
    printf("Process Arrival Time: \n");
    for(int i=0;i<n;i++)
    {   printf("P%d             ",i+1);
        scanf("%d",&P[i].AT);
        P[i].pid=(i+1);
        
        
    }
    printf("Enter the Burst Time of process:\n");
    printf("Process Burst Time:\n");
    for(int i=0;i<n;i++)
    {   printf("P%d           ",i+1);
        scanf("%d",&P[i].BT);
         temp[i]=P[i].BT;
        
    }

    int max_BT=P[0].BT;
    int max_index=0;
    for(int i=0;i<n;i++)
      {
          if(P[i].BT > max_BT)
         {
           max_BT = P[i].BT;
           max_index=i;
         }
      }    
      
    
    for(int t=0;count!=n;t++)
    {
        S_P=max_index;
        for(int i=0;i<n;i++)
        {
            if(P[i].BT<P[S_P].BT && (P[i].AT<=t && P[i].BT>0))
            {
                S_P=i;
            }
            
        }
        
        P[S_P].BT=P[S_P].BT-1;
        
       
        if(P[S_P].BT==0)
        {
            count++;
            P[S_P].CT=t+1;
            P[S_P].WT=t+1-P[S_P].AT-temp[S_P];
            P[S_P].TAT=t+1-P[S_P].AT;
           
        }
    
    }
    

   
    
    printf("Process   Arrival Time     Burst Time   Completion Time   Turnaround Time   Waiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t %d\t\t %d\t\t%d\t\t %d\t\t%d\n",P[i].pid,P[i].AT,temp[i],P[i].CT,P[i].TAT,P[i].WT);
    }
    return 0;
}

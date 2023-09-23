#include<stdio.h>
struct process
{
    int pid,BT,CT,WT,TAT,REM_BT;
};

struct process P[10];



int main()
{
    int n=0,tq=0,temp=0,time=0,i=0,count=0;
    printf("Enter the number of the process: ");
    scanf("%d",&n);
    printf("Enter the burst time of the process:\n");
    printf("Process Burst Time: \n");
    for(int i=0;i<n;i++)
    {   printf("P%d           ",(i+1)); 
        scanf("%d",&P[i].BT);
        P[i].pid=i+1;
        P[i].REM_BT=P[i].BT;
    }
    printf("Enter the Time Quantum: ");
    scanf("%d",&tq);
    
   
    while(1)
    {   for(i=0,count=0;i<n;i++)
        {
          temp=tq;
          if(P[i].REM_BT==0)
          {
            count++;
            continue;
          }
          if(P[i].REM_BT>tq)
          {
            P[i].REM_BT=P[i].REM_BT-tq;
          }
          else{
            if(P[i].REM_BT>=0)
            {
              temp=P[i].REM_BT;
              P[i].REM_BT=0;
            }
            }
            time=time+temp;
            P[i].CT=time;
            P[i].TAT=P[i].CT;
            P[i].WT=P[i].TAT-P[i].BT;
          
          }
          if(n==count)
          {
            break;
          }
      }

    printf("Process    Burst Time    Completion Time    Turnaround Time   Waiting Time \n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",P[i].pid,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
    }
  return 0;
  }

      
   
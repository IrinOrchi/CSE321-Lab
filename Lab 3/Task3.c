#include<stdio.h>
struct process
{
    int pid,AT,BT,CT,TAT,WT,PT;
};

struct process P[10];

int main()
{
    int n=0,temp[10],time=0,count=0,S_P=0;

    printf("Enter the number of the process: ");
    scanf("%d",&n);
    printf("Enter the Arrival Time of process:\n");
    printf("Process Arrival Time \n");
    for(int i=0;i<n;i++)
    {  
         printf("P%d             ",i+1);
        scanf("%d",&P[i].AT);
        P[i].pid=i+1;
    }
    
    printf("Enter the Burst Time of process:\n");
    printf("Process Burst Time\n");
    for(int i=0;i<n;i++)
    {   printf("P%d           ",i+1);
        scanf("%d",&P[i].BT);
        temp[i]=P[i].BT;
    }
    printf("Enter the priority of the process:\n");
    printf("Process Priority\n");
    for(int i=0;i<n;i++)
    {   printf("P%d         ",(i+1));
        scanf("%d",&P[i].PT);
    }
    
    int max_PT=P[0].PT;
    int max_index=0;
    for(int i=0;i<n;i++)
      {
          if(P[i].PT > max_PT)
         {
           max_PT = P[i].PT;
           max_index=i;
         }
      }    
    
    
    for(time=0;count!=n;time++)
    {
        S_P=max_index;
        for(int i=0;i<n;i++)
        {
            if(P[S_P].PT>P[i].PT && P[i].AT<=time && P[i].BT>0)
            {
                S_P=i;
            }
        }
        
        P[S_P].BT=P[S_P].BT-1;
        
       
        if(P[S_P].BT==0)
        {
            
            count++;
            P[S_P].CT=time+1;
            P[S_P].TAT=P[S_P].CT-P[S_P].AT;
            P[S_P].WT=P[S_P].TAT-temp[S_P];

           
        }
    }
    printf("Process   Arrival Time     Burst Time   Completion Time   Turnaround Time   Waiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",P[i].pid,P[i].AT,temp[i],P[i].CT,P[i].TAT,P[i].WT);
    }
    return 0;
}
  

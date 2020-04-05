#include<stdio.h>
#include<conio.h>
int main()
{
    int bt[10],Process[10],wt[10],tat[10];
    int at[10],Prior[10],i,j,Number_of_Process,tot=0,flag,temp,avg_wt,avg_tat;
    printf("Enter Number of Process:");
    scanf("%d",&Number_of_Process);
    printf("\nEnter Burst Time and Prior:\n");
    for(i=0;i<Number_of_Process;i++)
    {
        printf("\nP[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&bt[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&at[i]);
        printf("Enter Prior:");
        scanf("%d",&Prior[i]);
        Process[i]=i+1;
    }
    for(i=0;i<Number_of_Process;i++)
    {
        flag=i;
        for(j=i+1;j<Number_of_Process;j++)
        {
            if(Prior[j]<Prior[flag])
            flag=j;
        }
        temp=Prior[i];
        Prior[i]=Prior[flag];
        Prior[flag]=temp;
        temp=bt[i];
        bt[i]=bt[flag];
        bt[flag]=temp;
        temp=Process[i];
        Process[i]=Process[flag];
        Process[flag]=temp;
    }
    wt[0]=0;  
    for(i=1;i<Number_of_Process;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        tot+=wt[i];
    }
    avg_wt=tot/Number_of_Process;  
    tot=0;
    printf("_________________________________________________________________________________");
    printf("\nProcess\t       Burst Time           Waiting Time           Turn Around Time");
    for(i=0;i<Number_of_Process;i++)
    {
        tat[i]=bt[i]+wt[i];  
        tot+=tat[i];
        printf("\nProcess %d \t %d\t\t\t   %d\t\t\t%d",Process[i],bt[i],wt[i],tat[i]);
    }
	printf("\n________________________________________________________________________________");
    avg_tat=tot/Number_of_Process; 
    printf("\n\nAverage Waiting Time = %d",avg_wt);
    printf("\nAverage Turn Around Time= %d",avg_tat);
    return 0;
}


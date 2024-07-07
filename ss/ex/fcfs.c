#include<stdio.h>
struct fcfs
{
int btime;
int pid;
int wtime;
int ttime;
}
p[10];
int main()
{
int n,twtime=0,tat=0,i;
printf(" enter the no of process ");
scanf("%d",&n);
printf(" enter the burst time ");
for(i=0;i<n;i++)
{
p[i].pid=i+1;
scanf("%d",&p[i].btime);
}
p[0].wtime=0;
p[0].ttime=p[0].btime;
for(i=0;i<n;i++)
{
p[i].wtime=p[i-1].wtime+p[i-1].btime;
p[i].ttime=p[i].wtime+p[i].btime;
twtime+=p[i].wtime;
tat+=p[i].ttime;
}
printf(" total waiting time %d ",twtime);
printf(" average waiting time %d ",twtime/n);
printf(" total turn around time %d ",tat);
printf(" average turnaround time %d ",tat/n);
return 0;
}

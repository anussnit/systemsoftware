#include<stdio.h>
struct fcfs
{
int pid;
int bt;
int ct;
int tat;
int wt;
}
p[10];
int main()
{
int ttat=0,i,twat=0,j,n;
printf(" enter the no of process ");
scanf("%d",&n);
printf(" enter the burst time ");
for(i=0;i<n;i++)
{
scanf("%d",&p[i].bt);
p[i].pid=i+1;
}
//for(i=0;i<n;i++)
//printf(" %d ",p[i].bt);
p[0].ct=0;
for(i=0;i<n;i++)
{
p[i].ct=(p[i-1].ct+p[i].bt);
//printf(" ct is %d    ",p[i].ct);
//}
//for(i=0;i<n;i++)
//{
p[i].wt=(p[i].ct-p[i].bt);
//printf(" wt is %d   ",p[i].wt);
//}
//for(i=0;i<n;i++)
//{
p[i].tat=p[i].ct;
//printf(" tat is %d ",p[i].tat);
}
for(i=0;i<n;i++)
{
ttat+=p[i].tat;
twat+=p[i].wt;
}
printf(" \n total tat is %d \n",ttat);
printf(" \n total tw is %d \n",twat);
printf("\n average tat is %d \n",ttat/n);
printf("\n average tw is %d \n",twat/n);
return 0;
}



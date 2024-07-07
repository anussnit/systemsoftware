#include<stdio.h>
struct rrr
{
int p;
int bt;
int ct;
int tat;
int wt;
}
p[10];
int main()
{
int ttat=0,n,i,j,max=0,twt=0,t,temp=0;
printf(" enter the no of process ");
scanf("%d",&n);
printf(" enter the quantum time ");
scanf("%d",&t);
printf(" enter the burst time ");
for(i=0;i<n;i++)
{
printf(" process %d ",i+1);
scanf("%d",&p[i].bt);
p[i].tat=p[i].bt;
}
max=p[0].bt;
for(i=1;i<n;i++)
if(max<p[i].bt)
max=p[i].bt;
for(i=0;i<(max/t)+1;i++)
for(j=0;j<n;j++)
if(p[j].bt!=0)
if(p[j].bt<=t)
{
p[j].ct=temp+p[j].bt;
temp+=p[j].bt;
p[j].bt=0;
}
else
{
p[j].bt-=t;
temp+=t;
}
for(i=0;i<n;i++)
{
p[i].wt=p[i].ct-p[i].tat;
ttat+=p[i].tat;
twt+=p[i].wt;
}
printf(" total tat %f \n",ttat*1.0);
printf(" total twt %f \n",twt*1.0);
}
/*
enter the no of process 5
 enter the quantum time 2
 enter the burst time  
 process 1 5
 process 2 3
 process 3 1
 process 4 2
 process 5 3
 total tat 14.000000
 total twt 37.000000
 */

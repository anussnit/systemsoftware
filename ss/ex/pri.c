#include<stdio.h>
struct pri
{
int pid;
int bt;
int p;
int ct;
int tat;
int wt;
}
p[10];
int main()
{
int i,j,temp1,temp2,ttat=0,twt=0,n;
printf(" enter the no of process \n");
scanf("%d",&n);
printf(" enter the burst time ");
for(i=0;i<n;i++)
scanf("%d",&p[i].bt);
printf(" enter the priority ");
for(i=0;i<n;i++)
scanf("%d",&p[i].p);
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(p[j].p>p[j+1].p)
{
temp2=p[j].bt;
p[j].bt=p[j+1].bt;
p[j+1].bt=temp2;
temp1=p[j].p;
p[j].p=p[j+1].p;
p[j+1].p=temp1;
}
}
}
printf(" bt ");
for(i=0;i<n;i++)
printf("%d   ",p[i].bt);
printf(" p ");
for(i=0;i<n;i++)
printf("%d  ",p[i].p);
p[0].ct=0;
for(i=0;i<n;i++)
{
p[i].ct=p[i-1].ct+p[i].bt;
p[i].tat=p[i].ct;
p[i].wt=p[i].tat-p[i].bt;
}
for(i=0;i<n;i++)
{
ttat+=p[i].tat;
twt+=p[i].wt;
}
printf(" tat %d  \n",ttat);
printf(" wt %d  \n",twt);
printf(" ttat %d  \n",ttat/n);
printf(" twt  %d  \n",twt/n);
}


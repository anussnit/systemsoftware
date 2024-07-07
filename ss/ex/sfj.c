#include<stdio.h>
struct sjf
{
int pid;
int bt;
int ct;
int tat;
int wt;
int btt;
}
p[10];
int main()
{
int n,i,j,ttat=0,twt=0,temp;
printf(" enter the no of process ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf(" enter the pid %d \n",i+1);
printf(" enter the burst \n");
scanf("%d",&p[i].bt);
p[i].btt=p[i].bt;
}
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(p[j].bt>p[j+1].bt)
{
temp=p[j].bt;
p[j].bt=p[j+1].bt;
p[j+1].bt=temp;
}
}
}
for(i=0;i<n;i++)
printf("%d   ",p[i].bt);
for(i=0;i<n;i++)
{
p[i].ct=p[i-1].ct+p[i].bt;
p[i].tat=p[i].ct;
p[i].wt=p[i].ct-p[i].bt;
ttat+=p[i].tat;
twt+=p[i].wt;
}
printf("\n total tat %d \n",ttat);
printf("\n total wt %d \n",twt);
printf("\n avg wt %d \n",twt/n);
printf("\n avg tat %d \n",ttat/n);
return 0;
}

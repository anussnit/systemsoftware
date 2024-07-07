#include<stdio.h>
#include<stdlib.h>
struct rr
{
int pno,btime,sbtime,wtime,lst;
}p[10];
int main()
{
int pp=-1,ts,flag,count,ptm=0,i,n,twt=0,totttime=0;
printf("\n round robin scheduling............\n");
printf("enter no of processes:");
scanf("%d",&n);
printf("enter the time slice:");
scanf("%d",&ts);
printf("enter the burst time");
for(i=0;i<n;i++)
{
printf("\n process%d\t",i+1);
scanf("%d",&p[i].btime);
p[i].wtime=p[i].lst=0;
p[i].pno=i+1;
p[i].sbtime=p[i].btime;
}
printf("scheduling....\n");
do
{
flag=0;
for(i=0;i<n;i++)
{
count=p[i].btime;
if(count>0)
{
flag=-1;
count=(count>=ts)?ts:count;
printf("\n process %d",p[i].pno);
printf(" from %d ",ptm);
ptm+=count;
printf(" to %d ",ptm);
p[i].btime-=count;
if(pp!=i)
{
pp=i;
p[i].wtime+=ptm-p[i].lst-count;
p[i].lst=ptm;
}
}
}
}
while(flag!=0);
}
/*

 round robin scheduling............
enter no of processes:3
enter the time slice:4
enter the burst time
 process1       24

 process2       3

 process3       3
scheduling....

 process 1 from 0  to 4
 process 2 from 4  to 7
 process 3 from 7  to 10
 process 1 from 10  to 14
 process 1 from 14  to 18
 process 1 from 18  to 22
 process 1 from 22  to 26
 process 1 from 26  to 30
 
 */

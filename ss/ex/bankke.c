#include<stdio.h>
int main()
{
int max[20][20],need[20][20],alloc[20][20],i,j,n,r,avail[20];
printf(" enter the no of process ");
scanf("%d",&n);
printf(" enter the no of resources ");
scanf("%d",&r);
printf(" enter the alloc matrix\n ");
for(i=0;i<n;i++)
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
printf(" enter the max\n ");
for(i=0;i<n;i++)
for(j=0;j<r;j++)
scanf("%d",&max[i][j]);
printf(" enter the avail ");
for(i=0;i<r;i++)
scanf("%d",&avail[i]);
for(i=0;i<n;i++)
for(j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];
printf(" need matrix is ");
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<r;j++)
printf(" %d ",need[i][j]);
}
int sequencer[n],k,y,work[r],finish[n],ind=0;
for(i=0;i<n;i++)
finish[i]=0;
for(i=0;i<r;i++)
work[i]=avail[i];
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
if(finish[i]==0)
{
int flag=0;
for(j=0;j<r;j++)
{
if(need[i][j]>work[j])
{
flag=1;
break;
}
}
if(flag==0)
{
sequencer[ind++]=i;
for(y=0;y<r;y++)
work[y]+=alloc[i][y];
finish[i]=1;
}
}
}
}

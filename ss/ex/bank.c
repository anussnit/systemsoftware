#include<stdio.h>
int main()
{
int i,j,n,r,alloc[20][20],max[20][20],need[20][20],avail[20];
printf("\nenter the no of process ");
scanf("%d",&n);
printf("\nenter the no of resources ");
scanf("%d",&r);
printf("\n enter the alloc \n");
for(i=0;i<n;i++)
for(j=0;j<r;j++)
{
scanf("%d",&alloc[i][j]);
}
printf("\n enter the max \n");
for(i=0;i<n;i++)
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}
printf("\nenter the avail \n");
for(i=0;i<r;i++)
scanf("%d",&avail[i]);
printf("\n need matrix is \n");
for(i=0;i<n;i++)
for(j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<r;j++)
{
printf("%d  ",need[i][j]);
}
}
int ind=0,safesequence[n],k,flag,finish[n],work[r],y,count=0;
for(i=0;i<r;i++)
{
//printf(" avail  %d  ",avail[i]);
work[i]=avail[i];
}
for(i=0;i<n;i++)
{
finish[i]=0;
}
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
safesequence[ind++]=i;
for(y=0;y<r;y++)
work[y]+=alloc[i][y];
finish[i]=1;
}
}
}
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
if(safesequence[i]==j)
{
count++;
}
}
if(count==n)
{
printf(" the safesequence is ");
for(i=0;i<n;i++)
printf(" p%d",safesequence[i]);
}
else
{
printf(" not safe ");
}
}


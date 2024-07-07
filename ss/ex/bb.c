#include<stdio.h>
void main()
{
int i,j,alloc[10][10],need[10][10],avail[10][10],n,m,max[10][10];
printf(" enter the no:of process ");
scanf("%d",&n);
printf("enter the no:of resources ");
scanf("%d",&m);
printf(" enter the allocations \n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
scanf("%d",&alloc[i][j]);
printf(" enter the max \n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&max[i][j]);
for(i=0;i<n;i++)
for(j=0;j<m;j++)
need[i][j]=max[i][j]-alloc[i][j];
printf("need matrix is ");
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<m;j++)
printf("%d ",need[i][j]);
}
int work[n][m],flag,k,sequens[n],finish[n];
for(i=0;i<n;i++)
finish[i]=0;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
work[i][j]=need[i][j];
for(k=0;k<n;k++)
{
for(j=0;j<n;j++)
{
int flag=0;
if(finish[j]==0)
{

}

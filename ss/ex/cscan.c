#include<stdio.h>
void main()
{
int i,j,initial,n,d[20],temp,max,sum,loc;
printf("enter the no: of points ");
scanf("%d",&n);
printf("enter the initial head ");
scanf("%d",&initial);
printf("enter the disc queues ");
for(i=0;i<n;i++)
scanf("%d",&d[i]);
d[n]=initial;
n=n+1;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i;j++)
{
if(d[j]>d[j+1])
{
temp=d[j];
d[j]=d[j+1];
d[j+1]=temp;
}
}
}
max=199;
for(i=0;i<n;i++)
{
if(initial==d[i])
{
loc=i;
break;
}
}
for(i=loc;i<n;i++)
printf(" %d-->",d[i]);
printf("199-->0-->");
for(i=0;i<loc;i++)
printf(" %d-->",d[i]);
sum=(max-initial)+max+(d[loc-1]);
printf(" total sum is %d ",sum);
}

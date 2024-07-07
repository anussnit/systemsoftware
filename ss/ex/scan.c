#include<stdio.h>
void main()
{
int i,j,initial,d[20],n,max,sum,temp,loc;
printf(" enter the no: disk queu ");
scanf("%d",&n);
printf(" enter the initial head point ");
scanf("%d",&initial);
printf(" enter the disk queus ");
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
max=d[n-1];
for(i=0;i<n;i++)
{
if(d[i]==initial)
{
loc=i;
break;
}
}
for(i=loc;i>=0;i--)
{
printf("%d-->",d[i]);
}
printf("0-->");
for(i=loc+1;i<n;i++)
{
printf("%d-->",d[i]);
}
}

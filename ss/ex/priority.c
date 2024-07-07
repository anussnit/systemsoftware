#include<stdio.h>
int main()
{
int i,j,n,bt[10],p[10],compt[10],wt[10],tat[10],temp1,temp2;
float sumwt=0.0,sumtat=0.0;
printf("enter number of process :");
scanf("%d",&n);
printf(" enter the burst time of %d process \n",n);
for(i=0;i<n;i++)
scanf("%d",&bt[i]);
printf("enter the priority of %d process \n",n);
for(i=0;i<n;i++)
scanf("%d",&p[i]);
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(p[i]>p[j])
{
temp1=bt[i];
bt[i]=bt[j];
bt[j]=temp1;
temp2=p[i];
p[i]=p[j];
p[j]=temp2;
}
for(i=0;i<n;i++)
{
printf("bt %d   ",bt[i]);
printf(" p %d   ",p[i]);
}
compt[0]=bt[0];wt[0]=0;
for(i=1;i<n;i++)
{
compt[i]=bt[i]+compt[i-1];
printf("\n com  %d ",compt[i]);
}
for(i=0;i<n;i++)
{
tat[i]=compt[i];
wt[i]=tat[i]-bt[i];
sumtat+=tat[i];
sumwt+=wt[i];
}
printf(" total waiting time %f \n",sumwt);
printf(" average waiting time %f \n",sumwt/n);
printf(" total turnaround time %f \n",sumtat);
printf(" average turnaround time %f\n",sumtat/n);
}

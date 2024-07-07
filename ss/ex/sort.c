#include<stdio.h>
int main()
{
int a[10],i,j,n,temp;
printf("enter the number ");
scanf("%d",&n);
printf(" numbers is ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
for(j=0;j<n-i;j++)
{
if(a[j]>a[j+1])
{
temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;
}
}
for(i=0;i<n;i++)
printf(" %d  ", a[i]);
return 0;
}


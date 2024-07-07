#include<stdio.h>
void main()
{
int n,i,f,j,count=0,rs[40],m[40],pf=0,y;
printf(" enter the no of strings ");
scanf("%d",&n);
printf(" enter the reference string ");
for(i=0;i<n;i++)
scanf("%d",&rs[i]);
printf(" enter the no of frames ");
scanf("%d",&f);
for(i=0;i<n;i++)
m[i]=-1;
for(i=0;i<n;i++)
{
for(j=0;j<f;j++)
{
if(m[j]==rs[i])
break;
}
if(j==f)
{
m[count++]=rs[i];
pf++;
}
for(y=0;y<f;y++)
printf(" %d ",m[y]);
if(j==f)
printf(" PF %d ", pf);
printf("\n");
if(count==f)
count=0;
}
}


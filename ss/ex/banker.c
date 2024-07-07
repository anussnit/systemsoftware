#include<stdio.h>
int main()
{
int n,m,i,j,k,y,alloc[20][20],max[20][20],avail[50],ind=0;
printf(" Enter the no of processes ");
scanf("%d",&n);
printf("Enter the no of Resources "); 
scanf("%d",&m);
printf("enter the Allocation Matrix \n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
scanf("%d",&alloc[i][j]);
}
printf("Enter the Max Matrix \n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
scanf("%d",&max[i][j]);
}
printf("Enter the Available Matrix \n");
for(i=0;i<m;i++)
scanf("%d",&avail[i]);
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
need[i][j]=max[i][j]-alloc[i][j];
}
printf("NEED matrix is ");
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<m;j++)
printf("%d   ",need[i][j]);
}
int finish[n],safesequence[n],work[m],need[n][m];
for(i=0;i<m;i++)
{
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
for(j=0;j<m;j++)
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
for(y=0;y<m;y++)
work[y]+=alloc[i][y];
finish[i]=1;
}
}
}
}
printf("\n Following is the SAFE Sequence \n" );
for(i=0;i<=n-1;i++)
printf("P%d  ",safesequence[i]);
}



/*

 Enter the no of processes 5
Enter the no of Resources 4
enter the Allocation Matrix
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
Enter the Max Matrix
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
Enter the Available Matrix
1 5 2 0
NEED matrix is
0   0   0   0
0   7   5   0
1   0   0   2
0   0   2   0
0   6   4   2
 Following is the SAFE Sequence
P0  P2  P3  P4  P1



*/

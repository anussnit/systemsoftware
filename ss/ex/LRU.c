 #include<stdio.h>
void main()  
{
int i,j,k,min,rs[25],m[10],count[10],flag[25],n,f,pf=0,next=0;
printf("Enter the length of reference string ");
scanf("%d",&n);
printf("enter the reference string ");
for(i=0;i<n;i++)
{
scanf("%d",&rs[i]);
flag[i]=0;
}
printf("Enter the number of frames ");
scanf("%d",&f);
for(i=0;i<f;i++)
{
count[i]=0;
m[i]=-1;
}
printf("\n The page Replacement process is \n");
for(i=0;i<n;i++)
{
for(j=0;j<f;j++)
{
if(m[j]==rs[i])
{
printf(" first \n");
printf(" m[j]= %d \n",m[j]);
flag[i]=1;
printf(" next=%d \n",next);
count[j]=next;
next++;
printf(" next=%d \n",next);
}
}
if(flag[i]==0)
{
if(i<f)
{
m[i]=rs[i];
printf(" second part \n");
count[i]=next;
printf(" next=%d \n",next);
next++;
printf(" next=%d \n",next);
}
else
{
min=0;
for(j=1;j<f;j++)
if(count[min]>count[j])
{
min=j;
printf("%d \n",min);
}
m[min]=rs[i];
printf(" third ");
printf("\n rs[i]=%d \n",rs[i]); 
count[min]=next;
printf(" \n min= %d \n",min);
printf(" next=%d \n",next);
next++;
printf("\n next= %d \n",next);
}
pf++;
}
for(j=0;j<f;j++)
printf("%d\t",m[j]);
if(flag[i]==0)
printf(" PF No.  %d",pf);
printf("\n");
}
printf("\n The number of page faults using LRU are %d",pf);
}


/*

Enter the length of reference string 20
enter the reference string 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
Enter the number of frames 4

 The page Replacement process is
1       -1      -1      -1       PF No.  1
1       2       -1      -1       PF No.  2
1       2       3       -1       PF No.  3
1       2       3       4        PF No.  4
1       2       3       4
1       2       3       4
1       2       5       4        PF No.  5
1       2       5       6        PF No.  6
1       2       5       6
1       2       5       6
1       2       5       6
1       2       3       6        PF No.  7
1       2       3       7        PF No.  8
6       2       3       7        PF No.  9
6       2       3       7
6       2       3       7
6       2       3       1        PF No.  10
6       2       3       1
6       2       3       1
6       2       3       1

 The number of page faults using LRU are 10
 
 
 */

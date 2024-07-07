#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=5,x=0;
int producer()
{
--mutex;
++full;
--empty;
x++;
printf("produder produce %d item ",x);
++mutex;
}
int consumer()
{
--mutex;
--full;
++empty;
x--;
printf("consumer consumes %d item ",x);
++mutex;
}
int main()
{
int n,i;
for(i=0;i<=5;i++)
{
printf("enter 1.producer 2.consumer 3.exit ");
scanf("%d",&n);
switch(n)
{
case 1: if((mutex!=0)&&(empty!=0))
{
producer();
}
else
printf(" buffer is full ");
break;
case 2: if((mutex!=0)&&(full!=0))
{
consumer();
}
else
printf("buffer is empty");
break;
case 3:
exit(0);
break;
}
}
return 0;
}


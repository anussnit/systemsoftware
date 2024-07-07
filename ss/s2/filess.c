#include<stdio.h>
#include<string.h>
void main()
{
int i,j;
FILE *fp;
fp=fopen("kk.txt","r");
char line[20],line2[20];
fscanf(fp,"%s%s",line,line2);
for(i=0;i<20;i++)
printf("%c",line[i]);
printf("\n next \n");
for(i=0;i<20;i++)
printf("%c",line2[i]);
printf("\n next \n");
fscanf(fp,"%s",line);
for(i=0;i<20;i++)
printf("%c",line[i]);
fclose(fp);
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char hexadecimalnum[100];
int arrlen=0;
int decToHexa(int n)
{
long decimalnum,quotient,remainder;
int i,j=0;
decimalnum=(long)n;
quotient=decimalnum;
while(quotient!=0)
{
//remainder=quotient%16;
//if(remainder<10)
//hexadecimalnum[j++]=48+remainder;
//else
//hexadecimalnum[j++]=55+remainder;
//quotient=quotient/16;
remainder=quotient%6;
hexadecimalnum[j++]=(remainder<10)?(48+remainder):(55+remainder);
remainder=remainder/16;
}
arrlen=j;
for(i=j;i>=0;i--)
printf("%c",hexadecimalnum[i]);
return 0;
}
void main()
{
FILE *f1,*f2,*f3,*f4;
int loc,sa,l,op1,o,len,i;
unsigned int x;
char m1[20],la[20],op[20],otp[20],ch;
f1=fopen("input.txt","r");
f3=fopen("sysmtab.txt","w");
fscanf(f1,"%s %s %x",la,m1,&x);
printf("\n intermediate file\n");
if(strcmp(m1,"START")==0)
{
sa=(int)x;
loc=sa;
printf("\t %s\t%s\t%x\n",la,m1,x);
}
else
loc=0;
fscanf(f1,"%s%s",la,m1);
while(!feof(f1))
{
fscanf(f1,"%s",op);
printf("\n%x\t%s\t%s\t%s\n",loc,la,m1,op);
if(strcmp(la,"-")!=0)
{
fprintf(f3,"\n%x\t%s\n",loc,la);
}
f2=fopen("optab.txt","r");
fscanf(f2,"%s%d",otp,&o);
while(!feof(f2))
{
if(strcmp(m1,otp)==0)
{
loc=loc+3;
break;
}
fscanf(f2,"%s%d",otp,&o);
}
fclose(f2);
if(strcmp(m1,"WORD")==0)
{loc=loc+3;
}
else if(strcmp(m1,"RESW")==0)
{
op1=atoi(op);
loc=loc+(3*op1);
}
else if(strcmp(m1,"BYTE")==0)
{
if(op[0]=='X')
loc=loc+1;
else
{
len=strlen(op)-3;
loc=loc+len;
}
}
else if(strcmp(m1,"RESB")==0)
{
op1=atoi(op);
loc=loc+op1;
}
fscanf(f1,"%s%s",la,m1);
}
if(strcmp(m1,"END")==0)
{printf("\n\n Program length=\t");
decToHexa(loc-sa);
printf("\n");
}
}



/* 
 intermediate file
         **     START   2000

2000    **      LDA     FIVE

2003    **      STA     ALPHA

2006    **      LDCH    CHARZ

2006    **      STCH    C1

2006    ALPHA   RESW    1

2009    FIVE    WORD    5

200c    CHARZ   BYTE    C'Z'

200d    C1      RESB    1

200e    **      END     **


 Program length=        E
 */

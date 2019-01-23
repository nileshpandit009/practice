#include<stdio.h>
#include<conio.h>

void gen(int n)
{
if(n<=10)
{
printf("%d ",n);
gen(++n);
}
}

void main()
{
int n;
gen(1);
getch();
}
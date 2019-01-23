#include<stdio.h>
#include<conio.h>
void alpha(char);
int cnt = 0, x = 0, y = 0;

void main()
{
	clrscr();
	alpha('A');
	getch();
}

void alpha(char c)
{
	if(cnt == 4) {
		x = x + 5;
		++y;
		cnt = 0;
		gotoxy(x,y);
	}
	printf("%c",c);
	++cnt;
	if(c < 'Z')
		alpha(c+1);
}
#include<stdio.h>
//#include<conio.h>
char ch[30];

int count=0,i,st=0,x=0;
char stack[10],out[10];
char op[]={'+','-','*','/'};
char flag=0,temp,str,c;
void infix();

void pop();
int check_precedence(char ,char );


int main()
{
//clrscr();
	printf("\nEnter expression:\n");
	scanf("%s",&ch);
	while(ch[x]!='\0') {
		c=ch[x];
		infix();
		x++;
	}
	return 0;
//getch();
}

void infix()
{
	int p,k=0;
	char ch1;
	if(c=='(') {
		if(st>0) {
			printf("temp=");
			x++;
			while(ch[x]!=')') {
				printf("%c",ch[x]);
				x++;
			}
			printf("\ntemp1=%stemp",stack);
		}
		else if(st==0) {
			x++;
			while(ch[x]!=')') {
				stack[st]=ch[x];
				st++;
				count++;
				if(flag>0)
					break;
				if(count==3 && ch[x+1]==')') {
					printf("temp=%s",stack);
					pop();
					x=x+2;
					printf("\ntemp1=temp");
					while(ch[x]!='\0') {
						printf("%c",ch[x]);
						x++;
					}
					flag++;
				}
				else if(count==3 && ch[x+1]!=')') {
					break;
				}
				x++;
			}//#while
		}//#elseif
	}//#if
	else if(x<3) {
		stack[st]=c;
		st++;x++;
		while(x<3 && ch[x]!='(') {
			stack[st]=ch[x];
			st++;x++;
		}
		x--;
	}
	else {
		ch1=stack[1];
		p=check_precedence(ch1,ch[x]);
		if(p==1) {
			printf("temp=%s",stack);
			while(i<st) {
				stack[i]='\0';i++;
			}
			st=0;
			while(ch[x]!='\0' && ch[x]!=')') {
				stack[st]=ch[x];
				st++;x++;
			}
			printf("\ntemp1=temp%s",stack);
		}
		else if(p==2) {
			st--;
			printf("temp1=%c",stack[st]);
			stack[st]='\0';
			while(ch[x]!='\0' && ch[x]!=')') {
				printf("%c",ch[x]);
				x++;
			}
			printf("\ntemp=%stemp1",stack);
		}
	}
}//#infix

int check_precedence(char ch1,char c)
{
	int j,c1=0,c2=0;
	for(j=0;j<4;j++) {
		if(ch1==op[j])
			c1=j+1;
		else if(c==op[j])
			c2=j+1;
	}
	if(c1>c2)
		return 1;
	else
		return 2;
}

void pop()
{
	int j=0;

	while(j<=st) {
		stack[j]='\0';
		j++;
	}
}

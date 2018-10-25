#include<stdio.h>
#include<conio.h>
#include<ctype.h>
char symb,tsymb,y;
char infix[20],post[20];
int i=0,j=0,s[20],t=-1;
void push(int x)
{
s[++t]=x;
}
int pop()
{
return (s[t--]);
}
int priority( char x)
{
 if(x=='(')
 return (0);
else if(x=='+'||x=='-')
 return (1);
else if(x=='*'||x=='/')
 return (2);
else if(x=='$')
 return (3);
 else
 return (4);
}
void main()
{
clrscr();
printf("Enter infix expression:");
gets(infix);
while(infix[i]!='\0')
{
  symb=infix[i];
  i++;
  if(isdigit(symb))
  {
   post[j]=symb;
   j++;
  }
  else if(symb=='(')
  {
  push(symb);
  }
  else if(symb==')')
  {
   while((y=pop())!='(')
   {
    post[j]=y;
    j++;
  }
  }
   else

  {
    while((t!=-1)&&(priority(s[t])>=priority(symb)))
    {
    tsymb=pop();
    post[j]=tsymb;
    j++;
    }
    push(symb);
 }
}
   while(t!=-1)
   {
    tsymb=pop();
    post[j]=tsymb;
    j++;
   }
    puts(post);
    getch();
}
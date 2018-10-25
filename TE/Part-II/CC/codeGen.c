#include<string.h>
//#include<conio.h>
#include<stdio.h>
void main()
{
 char str[20],stack[20];
 int i,top=-1;
// clrscr();
 printf("Enter the postfix String:");
 scanf("%s",&str);
 for(i=0;i<strlen(str);i++)
 {
  if(str[i]=='+')
  {
   stack[++top]=str[i+1];
   printf("\nMOVER AREG, %c",stack[top-1]);
   printf("\nADD AREG, %c",stack[top]);
   top=top-2;
   printf("\nMOVEM AREG,P");
   stack[++top]='P';
  }
  else if(str[i]=='-')
  {
  stack[++top]=str[i+1];
   printf("\nMOVER AREG, %c",stack[top-1]);
   printf("\nSUB AREG, %c",stack[top]);
   printf("\nMOVEM AREG,Q");
   top=top-2;
   stack[++top]='Q';
  }
  else if(str[i]=='*')
  {
  stack[++top]=str[i+1];
   printf("\nMOVER AREG, %c",stack[top-1]);
   printf("\nMULT AREG, %c",stack[top]);
   printf("\nMOVEM AREG,R");
   top=top-2;
   stack[++top]='R';
  }
  else if(str[i]=='/')
  {
  stack[++top]=str[i+1];
   printf("\nMOVER AREG, %c",stack[top-1]);
   printf("\nDIV AREG, %c",stack[top]);
   printf("\nMOVEM AREG,S");
   top=top-2;
   stack[++top]='S';
  }
  else
  {
   stack[++top]=str[i];
  }
 }
// getch();
}

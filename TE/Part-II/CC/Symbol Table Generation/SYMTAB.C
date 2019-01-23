#include<stdio.h>
#include<string.h>
#include<conio.h>
char type[10][10]={"int","float","char"};
char *p,*q,*datatype;
int i;
int main()
{
 FILE *fp;
 int disp,counter=0;
 char *ch,*ch1;
 clrscr();
 fp=fopen("input.txt","r");
  if(fp==NULL)
   printf("\n File Not Exist...\n");
  else
  {
    printf("DataType      Symb        Size        Length      Refrence Line No.\n");

   while(!feof(fp))
   {
     fgets(ch,1024,fp);
     counter++;
     p=strtok(ch," ");
     for(i=0;i<3;i++)
     {
       if(strcmp(p,type[i])==0)
       {

	 datatype=p;
	 if(strcmp(p,"char")==0)
	 {
	   datatype=p;
	   printf("%s       ",p);
	   p=strtok(NULL," ");
	    disp=strlen(p)-3;
	   if(strncmp((p+disp),"];\n")==0)
	   {
	     q=strtok(p,"[");
	     ch1=q;
	     printf("%6s      ",q);
	     q=strtok(NULL,"]");
	     printf("%6d      ",sizeof(char));
	     printf("%6s      ",q);
	     printf("%6d      \n\n",counter);
	   }
	   else
	   {
	     printf("%s ",p);

	   }
	 }
	 else
	 {
	     printf("%s      ",p);
	     p=strtok(NULL,";");
	     printf("%5s      ",p);
	     if(strcmp(datatype,"float")==0)
	     {
	       printf("%5d      ",sizeof(float));
	       printf("%5d      ",sizeof(float));

	     }
	     else
	     {
	       printf("%5d      ",sizeof(int));
	       printf("%5d      ",sizeof(int));
	     }
	     printf("%5d      \n\n",counter);

	 }
	 //printf("%s",p);
	// p=strtok(NULL," ");

       }



    }
   }

 }


getch();
return 0;
}

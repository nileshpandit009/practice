#include<stdio.h>
#include<conio.h>
#include<string.h>

struct macro
{
	char mac_name[10];
	char mac_val[10];
};
struct macro mac[3];

void main()
{
	FILE *fp;
	char *fin, *p, *q;
	int i = 0, flag = 0;
	clrscr();
	fp = fopen("prog.txt","r");

	while(!feof(fp)) {
		fgets(fin,200,fp);
		p=strtok(fin," ");
		if(strcmp(p,"#define") == 0) {
			p = strtok(NULL," ");
			strcpy(mac[i].mac_name,p);
			p = strtok(NULL," ");
			strcpy(mac[i].mac_val,p);
			++i;
		}
		else {
			while(p) {
				flag = 0;
				for(i=0;i<3;i++){
					if(strcmp(p,mac[i].mac_name) == 0) {
						strcpy(q, mac[i].mac_val);
						printf("%s ",q);
						flag = 1;
					}
				}
				if(flag == 0)
					printf("%s ",p);
				p = strtok(NULL," ");
			}
		}
	}
	for(i=0;i<3;i++){
		printf("\nmacro name = %s", mac[i].mac_name);
		printf("\nmacro value = %s", mac[i].mac_val);
	}

	getch();
}

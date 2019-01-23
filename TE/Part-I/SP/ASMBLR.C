#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

char *mne[3][11] = {
			{"STOP", "ADD", "SUB", "MULT", "MOVER", "MOVEM",
				"COMP", "BC", "DIV", "READ", "PRINT"},
			{'\0', "START", "END", "ORIGIN", "EQU", "LTORG",
				'\0', '\0', '\0', '\0', '\0'},
			{'\0', "DC", "DS", '\0', '\0', '\0', '\0', '\0',
				'\0', '\0', '\0'}
			};
char *symtab[10][2];

int main()
{
	int i, j, m = -1, n = -1;
	int pflag = 0, tokcnt = 0, symcnt = 0, symflag = 0;

	char *fin, *str1, *unwanted, *newline, *buff, *strcon;
	char remove[] = {',', '\''};

	FILE *fp;
	clrscr();
	fp = fopen("C:\\TURBOC3\\BIN\\pass1.txt", "r");
	if(fp == NULL) {
		printf("\n\nFile not found\n");
		exit(0);
	}

	while(fgets(fin, 200, fp)) {
		newline = strchr(fin, '\n');
		if(newline)
			*newline = 0;
		for(i=0;i<2;i++) {
			unwanted = strchr(fin, remove[i]);
			if(unwanted)
				*unwanted = ' ';
		}
		tokcnt = 0;
		symflag = 0;
		str1 = strtok(fin, " ");
		do {
			pflag = 0;
			++tokcnt;
			for(i=0;i<3;i++) {
				for(j=0;j<11;j++) {
					if(pflag == 1)
						break;
					if(strcmp(str1, mne[i][j]) == 0) {
						printf("\n(%s,%c%d)", (i==0?"IS":(i==1?"AD":"DL")), (j<10?'0':0), j);
						pflag = 1;
					}
					else if(strcmp(str1, "AREG") == 0) {
						printf("(1)");
						pflag = 1;
					}
					else if(atoi(str1)) {
						printf("(C,%d)", atoi(str1));
						pflag = 1;
					}
				}
			}

			//To generate Symbol Table.
			if(pflag == 0) {
				for(i=0;i<10;i++)
					if(symtab[i][0] == str1)
						symflag = 1;
					if(symflag == 0) {
						++symcnt;
						n = -1;
						sprintf(buff,"0%d", symcnt);
						itoa(symcnt, strcon, 10);
						symtab[++m][++n] = str1;
						symtab[m][++n] = (symcnt<10 ? buff : strcon);
					}
					if(tokcnt > 1) {
						for(i=0;i<10;i++)
							if(symtab[i][0] == str1)
								printf("(S,%s)", symtab[i][1]);
					}
			}
		} while((str1 = strtok(NULL, " ")) != NULL);
	}

	getch();

	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>

char *mne[3][11] = {
			{"STOP", "ADD", "SUB", "MULT", "MOVER", "MOVEM",
				"COMP", "BC", "DIV", "READ", "PRINT"},
			{'\0', "START", "END", "ORIGIN", "EQU", "LTORG",
				'\0', '\0', '\0', '\0', '\0'},
			{'\0', "DC", "DS", '\0', '\0', '\0', '\0', '\0',
				'\0', '\0', '\0'}
			};
char *symtab[5][2];

/*
void codeGen(char *tmp)
{
	int i, j;
	for(i=0;i<3;i++) {
		for(j=0;j<11;j++) {
			if(strcmp(tmp, mne[i][j]) == 0)
				printf("\n(%s,%c%d)", (i==0?"IS":(i==1?"AD":"DL")), (j<10?'0':'\0'), j);
		}
	}
}
*/

int main()
{
	int i, j;

	char *fin, *str1, *newline;

	FILE *fp;
//	clrscr();
	fp = fopen("./pass1.txt", "r");
	if(fp == NULL) {
		printf("\n\nFile not found\n");
		exit(0);
	}

/*	for(i=0;i<3;i++) {
		for(j=0;j<11;j++) {
			if(mne[i][j] != NULL)
				printf("\n(%s,%c%d)", (i==0?"IS":(i==1?"AD":"DL")), (j<10?'0':'\0'), j);
		}
		printf("\n");
	}
*/

	while(fgets(fin, 200, fp)) {
		newline = strchr(fin, '\n');
		if (newline)
			*newline = 0;
		str1 = strtok(fin, " ");
		do {
//			codeGen(str1);
			for(i=0;i<3;i++) {
				for(j=0;j<11;j++) {
					if(strcmp(tmp, mne[i][j]) == 0)
						printf("\n(%s,%c%d)", (i==0?"IS":(i==1?"AD":"DL")), (j<10?'0':'\0'), j);
				}
			}
		} while((str1 = strtok(NULL, " ")) != NULL);
	}

	return 0;
}

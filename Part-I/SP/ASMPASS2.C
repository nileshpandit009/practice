#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp;
	char *fin;
	int LC = 0;
	fp = fopen("C:\\TURBOC3\\BIN\\PASS2.TXT", "r");

	if (!fp) {
		perror("\nFile not found !!!\n");
		exit(1);
	}

	while (fgets(fin, 200, fp)) {
	}
}
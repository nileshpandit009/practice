#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *fd;
	char ch;

	if ((fd = fopen("./input_file.c", "r+")) == NULL) {
		perror("\nCannot open file\n\n");
		exit(-1);
	}

	while ((ch = fgetc(fd)) != EOF) {
		if (ch == '/') {
			ch = fgetc(fd);
			if (ch == '/')
				while ((ch = fgetc(fd)) != '\n');
			else if (ch == '*') {
repeat:				while ((ch = fgetc(fd)) != '*');
				if ((ch = fgetc(fd)) != '/') goto repeat;
				ch = fgetc(fd);
			}
		}
		printf("%c", ch);
	}

	return 0;
}

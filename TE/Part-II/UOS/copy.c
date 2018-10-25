#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

char buffer[2048];

void file_copy(int src, int dest)
{
	int count;

	while ((count = read(src, buffer, sizeof(buffer))) > 0)
		write(dest, buffer, count);
}

int main (int argc, char *argv[])
{
	int fdold, fdnew;
	if (argc != 3) {
		printf("\nToo few arguments\n\n");
		exit(-1);
	}

	fdold = open(argv[1], 0444);
	if(fdold == -1) {
		printf("\nCannot open file %s\n\n", argv[1]);
		exit(-1);
	}

	fdnew = creat(argv[2], 0666);
	if (fdnew == -1) {
		printf("\nCannot create file %s\n\n", argv[2]);
		exit(-1);
	}

	file_copy(fdold, fdnew);
	return 0;
}

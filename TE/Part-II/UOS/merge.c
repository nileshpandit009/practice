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

int file_merge(int src1, int src2, int dest)
{
	file_copy(src1, dest);
	file_copy(src2, dest);
	return 0;
}

int main (int argc, char *argv[])
{
	int fdsrc1, fdsrc2, fddest;
	int ret_val;
	if (argc != 4) {
		printf("\nToo few arguments\n\n");
		exit(-1);
	}

	if((fdsrc1 = open(argv[1], 0444)) == -1) {
		printf("\nCannot open file %s\n\n", argv[1]);
		exit(-1);
	}

	if ((fdsrc2 = open(argv[2], 0444)) == -1) {
		printf("\nCannot open file %s\n\n", argv[2]);
		exit(-1);
	}

	if ((fddest = creat(argv[3], 0666)) == -1) {
		printf("\nCannot create file %s\n\n", argv[3]);
		exit(-1);
	}

	if ((file_merge(fdsrc1, fdsrc2, fddest)) != 0) {
		printf("\nOperation unsuccessful\n\n");
		exit(-1);
	}
	return 0;
}

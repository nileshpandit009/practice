#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
int main()
{
	struct stat statbuf;
	char dirpath[256];
	getcwd(dirpath,256);
	DIR *dir = opendir(dirpath);
	struct dirent *dp;
	for (dp=readdir(dir); dp != NULL; dp=readdir(dir)) {
		stat(dp->d_name, &statbuf);
		printf("the file name is %s \n", dp->d_name);
		printf("dir = %d\n", S_ISDIR(statbuf.st_mode));
		printf("file size is %ld in bytes \n", statbuf.st_size);
		printf("last modified time is %ld in seconds \n",
		statbuf.st_mtime);
		printf("last access time is %ld in seconds \n",
		statbuf.st_atime);
		printf("The device containing the file is %ld\n", statbuf.st_dev);
		printf("File serial number is %ld\n\n", statbuf.st_ino);
	}
	return 0;
}

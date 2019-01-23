#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(void)
{
    FILE *fp = NULL;
    int i = 0;
    char *msg, *data;
    data = (char*)calloc(50, sizeof(char));
    msg = (char*)calloc(50000, sizeof(char));

    fp = fopen("/home/nilesh/Programs/BE/Part-I/MDB/src_file", "w+");

    if (fp == NULL) {
        printf("\n\nFile error\n\n");
        exit(-1);
    }
    for (i = 1; i <= 100; i++) {
        sprintf(data, "%d %c %.2f %c\n", i, (65 + i), ((50.0 + i) / 1.0), 'C');
        strcat(msg, data);
    }

    fputs(msg, fp);
    fclose(fp);
    return 0;
}
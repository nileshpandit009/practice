#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(void)
{
    FILE *src_file;
    int no_of_disk, disk_num = 0;
    char path[100];

    printf("\n\nEnter number of disks:\n");
    scanf("%d", &no_of_disk);

    FILE *disks[no_of_disk];

    src_file = fopen("/home/nilesh/Programs/BE/Part-I/MDB/src_file", "r");

    if (src_file == NULL) {
        printf("\n\nSource file error\n\n");
        exit(-1);
    }

    for (int i = 0; i < no_of_disk; i++) {
        sprintf(path, "/home/nilesh/Programs/BE/Part-I/MDB/rr_disk%d", i);
        disks[i] = fopen(path, "w");
    }

    for (int i = 0; i < no_of_disk; i++) {
        if (disks[i] == NULL) {
            printf("\nFile error on file no %d\n", i+1);
            exit(-1);
        }
    }

    char line[30];

    while (fgets(line, sizeof(line), src_file) != NULL) {
        // printf("%s", line);
        fprintf(disks[disk_num], line);
        if (disk_num < no_of_disk-1)
            disk_num++;
        else
            disk_num = 0;
    }

    printf("\nPartitioning completed successfully\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
void getpara(const char *filename) {
	FILE *fp;
	char buf[1024];
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("open error!\n");
        return;
	}
	else {
		while (fgets(buf, sizeof(buf), fp) != NULL) {
		}
	}
}

FILE* open(const char* filename, const char* mode) {
    FILE* fp;
    fp = fopen(filename, mode);
    if(fp == NULL) {
        printf("%s 打开失败", filename);
        exit(-1);
    }
    return fp;
}


char c[1024];
void printContent(const char *fileName) {
    FILE* fp = open(fileName, "r");

    printf("\n======== %s ========\n", fileName);
    // 读取文本，直到碰到新的一行开始
    while(fgets(c, MAX_LINE, fp) != NULL) {
        printf("%s", c);
    }
    printf("\n");
    fclose(fp);
}

FILE*  merge(const char* f1, const char* f2, const char* mergeFileName) {
    FILE* fp1 = open(f1, "r");
    FILE* fp2 = open(f2, "r");
    FILE* fp3 = open(mergeFileName, "w");
    while(fgets(c, MAX_LINE, fp1) != NULL) {
        printf("%s", c);
        fprintf(fp3, "%s", c);
    }

    while(fgets(c, MAX_LINE, fp2) != NULL) {
        fprintf(fp3, "%s", c);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return fp3;
}

int main(int argc, char *argv[])
{
    if(argc != 4) {
        printf("%s", "./main <第一个文件路径> <第二个文件路径> <合并后文件路径>\n");
        exit(1);
    }

    merge(argv[1], argv[2], argv[3]);
    printContent(argv[1]);
   printContent(argv[2]);
    printContent(argv[3]);

    return 0;
}


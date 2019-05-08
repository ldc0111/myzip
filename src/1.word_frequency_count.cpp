/*************************************************************************
	> File Name: 1.word_frequency_count.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月30日 星期二 20时28分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define NUMCNT 256
#define BASE 128

void word_fre_count(const char *readfilename, long long *word_count,int *n) {
    if(word_count == NULL || readfilename == NULL) {
        printf("error word_count or readfilename line :%d \n",__LINE__);
        exit(1);
    }
    FILE *fp;
    char ch;
    if((fp = fopen(readfilename,"r")) == NULL) {
        printf("error read file line: %d \n", __LINE__);
        exit(1);
    }

    ch = fgetc(fp);
    while (ch != EOF) {
        //putchar(ch);
        if(word_count[ch + BASE] == 0) (*n)++;
        word_count[ch + BASE]++;
        ch = fgetc(fp);
    }
    fclose(fp);
    return ;
}
void write_file_list(const char *writefilename, long long *word_count,int *n) {
    if(word_count == NULL || writefilename  == NULL) {
        printf("error word_count line: %d \n",__LINE__);
        exit(1);
    }
    FILE *fp;
    if((fp = fopen(writefilename,"w")) == NULL) {
        printf("error write file line : %d \n", __LINE__);
        exit(1);
    }
    fprintf(fp,"%d\n", *n);
    for (int i = 0; i < NUMCNT; i++) {
        if(word_count[i] == 0) continue;
        fprintf(fp,"%d %d\n", i,word_count[i]);
    }
    fclose(fp);
    return ;
}

int main() {
    char ch;
    int n = 0;
    long long word_count[NUMCNT] = {0};
    const char *readfilename = "../samples/1.txt";
    const char *writefilename ="./list";
    word_fre_count(readfilename, word_count, &n);
    /*
    for (int i = 0; i < NUMCNT; i++) {
        printf("i = %d %d \n", i,word_count[i]);
    }*/
    write_file_list(writefilename, word_count,&n);


    return 0;
}

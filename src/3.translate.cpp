/*************************************************************************
	> File Name: translate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月30日 星期二 23时26分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./3.bitqueue.cpp"
#include "./3.maxnum.cpp"
#define NUMCNT 256
#define BASE 128

void init_tr(const char *file, char (*tr)[32]){
    if(file == NULL || tr == NULL) {
        printf("error init_tr file or tr is NULL line: %d\n", __LINE__);
        exit(1);
    }
    FILE *fp;
    if((fp = fopen(file,"r")) == NULL) {
        printf("error read file is NULL line: %d\n", __LINE__);
        exit(1);
    }
    int ind;
    while (fscanf(fp,"%d",&ind) != EOF) {
        fscanf(fp,"%s", tr[ind]);
    }
    fclose(fp);
}

void translate_func(const char *file) {
    if(file == NULL) {
        printf("error translate_func file is NULL line: %d\n", __LINE__);
        exit(1);
    }
}



int main() {
    char tr[256][32] = {0};
    const char *code_list_file = "./code_list";
    const char *translate_file = "../samples/1.txt";
    init_tr(code_list_file, tr);
    /*
    for (int i = 0; i < 256; i++) {
        if(strlen(tr[i]) <= 0) continue;
        printf("%d %s\n", i, tr[i]);
    }*/
    translate_func(translate_file);

    return 0;
}

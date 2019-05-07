/*************************************************************************
	> File Name: 4.decompression.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月07日 星期二 19时22分09秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./4.hash.cpp" 

#define NUMCNT 256
//#define BASE 128

void init_tr(const char *file, char (*tr)[40]){
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


int main() {
    char tr[256][40] = {0};
    const char *code_list_file = "./code_list";
    const char *translate_file = "../samples/1.txt";
    const char *save_file = "./trans_file.myzip";
    const char * big_byte_file = "./byte_num";
    init_tr(code_list_file, tr);

    return 0;
}

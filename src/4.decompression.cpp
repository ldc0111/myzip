/*************************************************************************
	> File Name: 4.decompression.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月07日 星期二 19时22分09秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./4.huff.cpp" 

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
node * init_huff_tree(char (*tr)[40]){
    node *root = init_huff();
    
    int flag = 0, node_num = 1;
    for (int i = 0; i < NUMCNT; i++) {
        if(strlen(tr[i]) == 0) continue;
        //printf("tr[%d] : %s\n", i, tr[i]);
        node_num += insert_huff(root, tr[i], i);
        //printf("search %s key %d\n", tr[i], search_huff(root, tr[i]));
        flag += 1;
    }
    //printf("%d %d \n", flag, node_num);
    return root;
}

FILE* init_filep(const char *file,const char *str,const char *rw){
    if(file == NULL || str == NULL) {
        printf("error init_filep file or str is NULL line : %d\n", __LINE__);
    }
    FILE *fp = NULL;
    if((fp = fopen(file,rw)) == NULL) {
        printf("error init_filep %s is NULL line: %d\n", str, __LINE__);
        exit(1);
    }
    return fp;
}


void reduction_func(node *root, const char *save_file, const char *reduction_file) {
    if (root == NULL || save_file == NULL|| reduction_file == NULL) {
        printf("error reduction_func root ,save_file or reduction_file is NULL line: %d\n", __LINE__);
        exit(1);
    }
    FILE *fp_s = init_filep(save_file,"fp_s","r");
    FILE *fp_r = init_filep(reduction_file,"fp_r", "w");
}

int main() {
    char tr[NUMCNT][40] = {0};
    const char * code_list_file = "./code_list";
    const char * save_file = "./trans_file.myzip";
    const char * big_byte_file = "./byte_num";
    const char * reduction_file = "./reduction_file";
    init_tr(code_list_file, tr);
    node *huff_root = init_huff_tree(tr);

    reduction_func(root, save_file, reduction_file);
    return 0;
}

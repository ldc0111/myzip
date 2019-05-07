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

void translate_func(const char *file, const char *save_file, const char *big_byte_file,char (*tr)[40]) {
    if(file == NULL) {
        printf("error translate_func file is NULL line: %d\n", __LINE__);
        exit(1);
    }
    FILE *fp = NULL,*fpsave = NULL,*fpbyte = NULL;
    char ch, *str;
    int num;
    bitqueue *q = NULL;
    bignum *b = NULL;
    q = init_bitqueue();
    b = init_bignum();
    if((fp = fopen(file,"r")) == NULL) {
        printf("error read file line: %d\n", __LINE__);
        exit(1);
    }
    if((fpsave = fopen(save_file, "w")) == NULL) {
        printf("error write file line: %d\n", __LINE__);
        exit(1);
    }
    
    ch = fgetc(fp);
    while (ch != EOF) {
        //直接这么加有问题
        //ch = ch + BASE; 
        //printf("%d\n",ch + BASE);
        int ind = ch + BASE;

        int n = push_bitqueue(q, tr[ind]);
        add_big(b,n);
        //队列快满了
        if(empty_bitqueue80(q)) {
            //将编码后的数据压入文件
            str = pop_str_bitqueue(q);
            fprintf(fpsave,"%s",str);
        }
        ch = fgetc(fp);
    }
    str = pop_ch_bitqueue(q, &num);
    fprintf(fpsave,"%c", str[0]);

    if((fpbyte = fopen(big_byte_file, "w")) == NULL) {
        printf("error big_byte_file  line: %d\n", __LINE__);
        exit(1);
    }
    
    output_big_to_file(b,big_byte_file);

    fclose(fpsave);
    fclose(fp);
}



int main() {
    char tr[256][40] = {0};
    const char *code_list_file = "./code_list";
    const char *translate_file = "../samples/1.txt";
    const char *save_file = "./trans_file.myzip";
    const char * big_byte_file = "./byte_num";
    init_tr(code_list_file, tr);
    /*
    for (int i = 0; i < 256; i++) {
        if(strlen(tr[i]) <= 0) continue;
        printf("%d %s\n", i, tr[i]);
    }*/
    translate_func(translate_file, save_file, big_byte_file,tr);
    printf("over!\n");
    return 0;
}

/*************************************************************************
	> File Name: 3.maxnum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月07日 星期二 10时52分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BIGSIZE 1000

typedef struct bignum{
    char *data;
    int size;
}bignum;
bignum *init_bignum() {
    bignum *b = (bignum *)calloc(sizeof(bignum), 1);
    b->data = (char*)calloc(sizeof(char), BIGSIZE);
    return b;
}

int add_big(bignum *b, int num){
    if(b == NULL) {
        printf("error add_big b is NULL line: %d\n", __LINE__);
        exit(1);
    }
    int ind = 0;
    for (ind; num; ind++) {
        b->data[ind] += num % 10;
        num /= 10;
    }
    if(b->size < ind - 1) b->size = ind - 1;
    ind  = 0;
    for (; ind <= b->size; ind++){
        if(b->data[ind] < 10) continue;
        b->data[ind + 1] += 1;
        b->data[ind] %= 10;
        if(ind == b->size) b->size += 1;
    }
    return ind;
}

int sub_big(bignum *b, int num) {
    if(b == NULL) {
        printf("error sub_big b is NULL line: %d\n", __LINE__);
        exit(1);
    }
    int ind = 0;
    for (; ind <= b->size; ind++){
        int temp = num % 10;
        if(b->data[ind] < temp) {
            b->data[ind + 1] -= 1;
            b->data[ind] += 10;
        }
        b->data[ind] -= temp;
        num /= 10;
    }
    while (b->data[b->size] == 0) b->size -= 1;
    return ind;
}

int compare_big(bignum *b, int num) {
    char *s;
    s = (char *)calloc(sizeof(char), 20);
    sprintf(s, "%d", num);
    int len  = strlen(s);
    for (int i = 0; i * 2 + 1< len; i++) {
        s[i] ^= s[len - i - 1];
        s[len - i - 1] ^= s[i];
        s[i] ^= s[len - i - 1];
    }
    //-1 0 1;
    if(len - 1 < b->size) {
        return 1;
    }else if(len - 1> b->size){
        return -1;
    }else {
        for (int i = len - 1; i >= 0; i--) {
            if(b->data[i] == (s[i] - '0')) continue;
            else if(b->data[i] > (s[i] - '0')) return 1;
            else return -1;
        }

    }
    return 0;
};

void output_big(bignum *b) {
    if (b == NULL) {
        printf("error output_big b is NULL : %d\n", __LINE__);
        exit(1);
    }
    for (int i = b->size; i >= 0; i--) {
        printf("%d", b->data[i]);
    }
    printf("\n");
    return ;
}

void output_big_to_file(bignum *b,const char *file) {
    if (b == NULL) {
        printf("error output_big b is NULL : %d\n", __LINE__);
        exit(1);
    }
    FILE *fp = NULL;
    if((fp = fopen(file,"w")) == NULL) {
        printf("error output_big_to_file  fp is NULL line: %d\n", __LINE__);
        exit(1);
    }
    for (int i = b->size; i >= 0; i--) {
        fprintf(fp,"%d", b->data[i]);
    }
    return ;
}
void clear_big(bignum *b) {
    if(b == NULL) return ;
    if (b->data != NULL) free(b->data);
    free(b);
    return ;
}

/*
int main() {
    bignum *b = NULL;
    b = init_bignum();
    add_big(b,10);
    output_big(b);
    add_big(b,20);
    output_big(b);
    add_big(b,30);
    output_big(b);
    add_big(b,40);
    output_big(b);
    add_big(b,50);
    output_big(b);
    add_big(b,60);
    output_big(b);
    printf("compare_big %d\n", compare_big(b, 200));
    printf("compare_big %d\n", compare_big(b, 210));
    printf("compare_big %d\n", compare_big(b, 220));
    sub_big(b,60);
    output_big(b);
    sub_big(b,50);
    output_big(b);
    sub_big(b,40);
    output_big(b);
    sub_big(b,30);
    output_big(b);
    sub_big(b,20);
    printf("compare_big %d\n", compare_big(b, 200));
    printf("compare_big %d\n", compare_big(b, 10));
    printf("compare_big %d\n", compare_big(b, 8));
    output_big(b);
    sub_big(b,10);
    output_big(b);
    return 0;
}

*/

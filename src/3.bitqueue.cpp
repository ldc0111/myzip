/*************************************************************************
	> File Name: 3.bitqueue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月04日 星期六 15时33分02秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BITSIZE 10000000


typedef struct bitqueue{
    char *data;
    int size;
    int ind;
    int tail;
}bitqueue;


bitqueue* init_bitqueue() {
    bitqueue * q = (bitqueue *)calloc(sizeof(bitqueue), 1);
    if (q == NULL) {
        printf("error init_bitqueue q is null line: %d\n", __LINE__);
        exit(1);
    }
    q->data = (char *)calloc(sizeof(char), BITSIZE);
    if (q->data == NULL) {
        printf("error init_bitqueue q->ch is null line: %d\n", __LINE__);
        exit(1);
    }
    return q;
}

void add_byte(bitqueue *q, const char *ch) {
    if(q == NULL || ch == NULL) {
        printf("error add_byte q or ch is NULL line: %d\n", __LINE__);
        exit(1);
    }
    if(q->ind != 7) q->ind++;
    else {
        q->tail += 1;
        q->ind = 0;
    }
    q->data[q->tail] = q->data[q->tail] &  (*ch - '0') << q->ind;
    return ;
}


int push_bitqueue(bitqueue *q, const char *s) {
    if(q == NULL || s == NULL) {
        printf("error push_bitqueue q or s is NULL line: %d\n", __LINE__);
        exit(1);
    }
    int i = 0;
    for (; s[i]; i++) {
        printf("%c",s[i]);
        if(s[i] == '0' || s[i] == '1') {
            add_byte(q, &s[i]);
        } else {
            printf("error s[i] line: %d\n", __LINE__);
            exit(1);
        }
    }
    printf("\n");
    return i;
}

int empty_bitqueue(bitqueue *q) {
    if(q == NULL) {
        printf("error empty_bitqueue q is NULL line: %d \n", __LINE__);
        exit(1);
    }
    if(q->tail== 0 && q->ind == 0) {
        return 1;
    } else {
        return 0;
    }
}
int empty_bitqueue80(bitqueue *q) {
    if(q == NULL) {
        printf("error empty_bitqueue80 q is NULL line: %d \n",__LINE__);
        exit(1);
    }
    if(q->tail *1.25 > q->size) {
        return 1;
    }
    return 0;
}

char * pop_str_bitqueue(bitqueue *q) {
    if(q == NULL) {
        printf("error pop_str_bitqueue q is null line: %d\n", __LINE__);
        exit(1);
    }
    int size  = q->tail;
    char *str = (char *)malloc(sizeof(char) * (size + 1));
    if (str == NULL) {
        printf("error pop_str_bitqueue str is null line: %d\n", __LINE__);
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        //printf("%c ", q->data[i]);
        str[i] = q->data[i];
    }
    str[size] = 0;
    q->data[0] = q->data[q->tail];
    q->tail = 0;
    //printf("str = %s\n",str);
    return str;
}

char * pop_ch_bitqueue(bitqueue *q, int *num) {
    if(q == NULL) {
        printf("error pop_ch_bitqueue q is null line: %d\n", __LINE__);
        exit(1);
    }
    char *ch = (char *)malloc(sizeof(char) * 1);
    if (ch == NULL) {
        printf("error pop_str_bitqueue str is null line: %d\n", __LINE__);
        exit(1);
    }
    //printf("%x %d\n",q->data[0],q->ind);
    *ch = q->data[0];
    *num = q->ind;
    //printf("%d \n", *num);
    return ch;
}

void clear_bitqueue(bitqueue *q) {
    if(q == NULL) return ;
    if(q->data != NULL) free(q->data);
    free(q);
    return ;
}

//test
int main() {
    const char *str1 = "fasfasfda";
    const char *str2 = "0101";
    const char *str3 = "01011101";
    const char *str4 = "0101010110101010101010101010101010101010101010101010";
    const char *str5 = "1";

    bitqueue *q = NULL;
    q = init_bitqueue();
    int n = 0;

    //push_bitqueue(q,str1);
    printf("%d\n",push_bitqueue(q,str2));
    printf("%d\n", push_bitqueue(q,str3));
    printf("%d\n",push_bitqueue(q,str4));
    //push_bitqueue(q,str5);
    //1
    //printf("%d\n",empty_bitqueue(q));
    //2
    //printf("%x ",*pop_ch_bitqueue(q, &n));
    //printf(" %d\n", n);
    //3
    printf("str = %s\n", pop_str_bitqueue(q));
    printf("%x\n",*pop_ch_bitqueue(q, &n));

    return 0;
}

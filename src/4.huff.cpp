/*************************************************************************
	> File Name: 4.huff.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月07日 星期二 23时28分06秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUMCNT 256
#define BASE 128

typedef  struct node{
    int key;
    struct node *lchild, *rchild;
}node;


node* getNewNode(int key) {
    node *p = (node *)calloc(sizeof(node),1);
    p->key = key;
    return p;
}

node *init_huff(){
    return getNewNode(-1);
}

int insert_huff(node *root, const char *str, int key) {
    if (root == NULL ||str == NULL) {
        printf("error insert_huff root or str is NULL line: %d", __LINE__);
        exit(1);
    }
    //printf("str[%d] : %s\n", key, str);
    node *p = root;
    int new_node = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '0') {
            if(p->lchild == NULL) new_node += 1, p->lchild = getNewNode(-1);
            p = p->lchild;
        }else if(str[i] == '1'){
            if(p->rchild == NULL) new_node += 1, p->rchild = getNewNode(-1);
            p = p->rchild;
        } else {
            printf("error str[i] is Illegal line : %d\n", __LINE__);
            exit(1);
        }
    }
    p->key = key;
    return new_node; 
}


int search_huff(node *root, const char *str) {
    if(root == NULL || str == NULL) {
        printf("error search_huff root or str is NULL line: %d\n", __LINE__);
        exit(1);
    }
    node *p = root;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '0') {
            if(p->lchild == NULL) return -1;;
            p = p->lchild;
        }else if(str[i] == '1'){
            if(p->rchild == NULL) return -1;;
            p = p->rchild;
        } else {
            printf("error str[i] is Illegal line : %d\n", __LINE__);
            exit(1);
        }
    }
    return p->key;
}


void close_huff(node *root) {
    if(root  == NULL) return ;
    close_huff(root->lchild);
    close_huff(root->rchild);
    free(root);
}
/*
int main() {



    return 1;
}

*/

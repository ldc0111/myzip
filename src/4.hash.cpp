/*************************************************************************
	> File Name: 4.hash.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月07日 星期二 20时38分41秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMCNT 256
#define BASE 128;

typedef struct Node{
    char *str;
    int key;
    struct Node *next;
}Node;

typedef struct HashTable{
    Node **data;
    int size;
}HashTable;

Node *init_node(char *str,Node *head,int key){
    Node *p = (Node *)malloc(sizeof(Node));
    if(p == NULL) {
        printf("error init_node  p is NULL line: %d\n", __LINE__);
        exit(1);
    }
    p->str = strdup(str);
    if(p->str == NULL) {
        printf("error init_node  p->str is NULL line: %d\n", __LINE__);
        exit(1);
    }
    p->key = key;
    p->next = head;
    return p;
}

HashTable * init_hasttable(int n){
    HashTable * h = (HashTable * )calloc(sizeof(HashTable), 1);
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *),h->size);
    return h;
}

int BKDRHash(char *str){
    int seed = 31,hash = 0;
    for(int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int insert_hash(HashTable * h,char *str,int key){
    if (h == NULL || str == NULL) {
        printf("error insert_hash h or str is line: %d\n", __LINE__);
        exit(1);
    }
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str,h->data[ind],key);
    if(h->data == NULL) {
        printf("error insert_hash h->data is NULL", __LINE__);
        exit(1);
    }
    return 1;
}

int search_hash(HashTable * h, char *str){
    if(h == NULL ||str == NULL) {
        printf("error h or str is NULL line: %d\n", __LINE__);
        exit(1);
    }
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while(p && strcmp(p->str, str)) p->next;
    if(p == NULL) return -1;
    return p->key;
}

void clear_node(Node * node){
    if(node == NULL) return ;
    Node *p = node, *q;
    while(p){
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hasttable(HashTable * h){
    if(h == NULL) return ;
    for(int i = 0; i  < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
    return;
}

/*


int main(){
    
    int op;
    char str[100];
    HashTable *h = init_hasttable(NUMCNT * 2);
    int k = 0;
    while(scanf("%d%s",&op,str) != EOF){
        switch (op){
            case 0:{
                printf("insert %s to hast tabile\n", str);
                insert(h,str,k);
            }break;
            case 1:{
                printf("search %s result = %d\n", str,search(h,str));
            }break;
        }
        k++;
    }

    return 0;
}

*/

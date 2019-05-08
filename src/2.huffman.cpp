/*************************************************************************
	> File Name: huffman.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月30日 星期二 22时15分08秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMCNT 256
#define BASE 128

#define swap(a,b){\
    __typeof(a) __temp = a; a = b; b = __temp;\
}


typedef struct node{
    int key,freq;
    struct node *lchild, *rchild;
}node;

typedef struct heap{
    node **data;
    int size,cnt;
}heap;

node * getNewnode(int n){
    node *p = (node *)malloc(sizeof(node));
    p->freq = n;//节点内部的权重
    p->key = -1;//节点数值，非叶子节点没有数值
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

heap * init(int n){
    heap *p = (heap * )malloc(sizeof(heap));
    p->data = (node **)calloc(sizeof(node*),(n + 1));
    p->cnt = 0;
    p->size = n;
    return p;
}
int empty(heap *h){
    return h->cnt <= 0;
}
void push(heap *h, node *val){
    if(h->cnt >= h->size) return;
    h->data[++(h->cnt)] = val;
    int ind = h->cnt;
    while (ind > 1) {
        if (h->data[ind]->freq > h->data[ind >> 1]->freq) break;
        swap(h->data[ind], h->data[ind >> 1]);
        ind >>= 1;
    }
}
node* top(heap *h){
    return h->data[1];
}

void  pop(heap *h){
    if(empty(h)) return ;
    h->data[1] = h->data[(h->cnt)--];
    int ind = 1;
    while((ind << 1) <= h->cnt){
        int temp = ind;
        if(h->data[temp]->freq > h->data[ind << 1]->freq) temp = ind << 1;
        if((ind << 1 | 1) <= h->cnt && h->data[temp]->freq > h->data[ind << 1 | 1]->freq) temp = ind << 1|1;
        if(temp == ind) break;
        swap(h->data[temp], h->data[ind]);
        ind = temp;
    }
    return ;
}
int count(heap *h){
    return h->cnt;
}


node* builld_haffman(heap *h){
    node *root = NULL;
    while(count(h) != 1){
        node * a = top(h);
        pop(h);
        node *b = top(h);
        pop(h);
        node *p = getNewnode(a->freq + b->freq);
        p->lchild = a;
        p->rchild = b;
        push(h,p);
    }
    return top(h);
}

void preorder(node *root){
    if(root == NULL) return ;
    //printf("%d", root->freq);
    printf("%d",root->key);
    if(root->lchild != NULL || root->rchild != NULL){
        printf("(");
        preorder(root->lchild);
        printf(",");
        preorder(root->rchild);
        printf(")");
    }
}
void inorder(node *root){
    if(root == NULL) return ;
    inorder(root->lchild);
    printf(" %d ", root->freq);
    inorder(root->rchild);
}
void output(heap *h){
    printf("Arr = [");
    for(int i = 1; i <= h->cnt; i++){
        printf(" %d",h->data[i]->freq);
    }
    printf(" ]\n");
}

void extract_code(node *root,char (*code)[40],int k,char *buff){
    buff[k] = 0;
    if(root->key != -1){
        strcpy(code[root->key],buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild,code,k + 1,buff);
    buff[k] = '1';
    extract_code(root->rchild,code,k + 1, buff);
}

heap *read_list(){
    int n,a,b;
    FILE *fp;
    if((fp = fopen("./list", "r")) == NULL) {
        printf("error list  line :%d\n", __LINE__);
        exit(1);
    }
    fscanf(fp,"%d", &n);
    heap *h = init(n);
    for(int i = 0; i < n; i++){
        fscanf(fp,"%d%d",&a,&b);
        //printf("%d %d\n",a,b);
        node* te = getNewnode(b);
        te->key = a;
        push(h,te);
    }
    return h;
}

void write_code_list(node *root){
    FILE * fp;
    char code[256][40] = {0},buff[40];

    if((fp = fopen("./code_list", "w")) == NULL) {
        printf("error code_list  line :%d\n", __LINE__);
        exit(1);
    }
    extract_code(root,code,0,buff);
    for(int i = 0; i < 256; i++){
        if(code[i][0] == 0) continue;
        fprintf(fp,"%d %s\n",i,code[i]);
    }
}

void close_huffman(node *root) {
    if(root  == NULL) return ;
    close_huffman(root->lchild);
    close_huffman(root->rchild);
    free(root);
}

int main(){
    heap *h = NULL;
    h = read_list();
    //output(h);
    
    node *root = builld_haffman(h);
    //preorder(root);
    //printf("\n");
    write_code_list(root);
    return 0;
}


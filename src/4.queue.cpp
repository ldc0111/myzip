/*************************************************************************
	> File Name: 4.queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月08日 星期三 11时54分40秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Queue{
    char *data;
    int head,tail,length, cnt;
}Queue;

Queue *init_queue(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n;
    q->data = (char *)malloc(sizeof(char) * n);
    q->head = 0;q->tail = -1;
    q->cnt = 0;
}

int push_queue(Queue *q, const char value){
    if(q->cnt == q->length) return 0;
    q->tail += 1;
    q->tail %= q->length;
    q->cnt +=1;
    q->data[q->tail] = value;
    return 1;
}


int push_str_queue(Queue *q, const char *str) {
    if(q == NULL || str  == NULL) {
        printf("error push_str q str is NULL line:%d\n", __LINE__);
        exit(1);
    }
    if(q->cnt + strlen(str) > q->length) {
        printf("error str is too long line: %d\n", __LINE__);
        exit(1);
    }
    for (int i = 0; str[i]; i++) {
        push_queue(q,str[i]);
    }
    return 0;
}

int empty_queue(Queue *q){
    return q->cnt == 0;
}

int count_queue(Queue *q) {
    return q->cnt;
}

void pop_queue(Queue *q){
    if(empty_queue(q)) return ;
    q->head += 1;
    if(q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return ;
}

char front_queue(Queue *q){
    if(empty_queue(q)) return 0;
    return q->data[q->head];
}
void clear_queue(Queue * q){
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}
void output_queue(Queue *q) {
    printf("Queue = [");
    for(int i = 0; i < q->cnt; i++) {
        int ind = (q->head + i) % q->length;
        printf(" %d", q->data[ind]);
        i + 1 == q->cnt || printf(",");
    }
    printf(" ]\n");
}
/*
int main() {



    return 0;
}*/

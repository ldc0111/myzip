/*************************************************************************
	> File Name: 3.trans_file.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月08日 星期三 20时12分15秒
 ************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



int main() {
    const char *str = "./trans_file.myzip";
    FILE *fp = NULL;
    if((fp = fopen(str,"r")) == NULL) {
        printf("error");
        exit(1);
    }
    int flag = 0;
    char ch;
    while((ch = fgetc(fp))!= EOF){
        flag++;
    }
    printf("%d\n",flag);
    return 0;
}

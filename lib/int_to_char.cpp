/*************************************************************************
	> File Name: int_to_char.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月08日 星期三 16时21分31秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>






int main() {
    FILE *fp = NULL;
    if((fp = fopen("./1.int_to_char","w")) == NULL) {
        printf("error line: %d\n", __LINE__);
        exit(1);
    }
    int a = -52;
    char ch;
    ch = a;
    printf("%c\n",ch);
    //fputc(ch,fp);
    fputc(a,fp);
    fclose(fp);


    return 0;
}

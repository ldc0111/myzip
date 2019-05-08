/*************************************************************************
	> File Name: 1.fprintf.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月07日 星期二 17时05分09秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {
    char str1[20] = "fasdfasdf";
    char str2[20] = "0000000fasdf";
    FILE * fp = NULL;
    if((fp = fopen("./fprint.txt","w")) == NULL) {
        printf("error\n");
        exit(1);
    }
    fprintf(fp,"%s",str1);
    fprintf(fp,"%s",str2);

    fclose(fp);

}

#include <sys/stat.h>
#include<stdio.h>
#include<time.h>
#include<sys/types.h>

#include "gloable.h"

int mk_trace_file () {
    //获取当前时间的函数
    time_t nowtime;
    struct tm *timeinfo;
    time(&nowtime);
    timeinfo=localtime(&nowtime);
    char *txtname = NULL;
    txtname = asctime(timeinfo);//结果转变为字符串

    mkdirectory();
    int i;
    for(i=0;txtname[i]!='\0';i++)
    {
       int j=7+i;
       pathname[j]=txtname[i];
    }
    pathname[i+7]='.'; //加上后缀 .txt的
    pathname[i+8]='t';
    pathname[i+9]='x';
    pathname[i+10]='t';
    pathname[i+11]='\0';//最后别忘记加上这个

    FILE *fp;
    if((fp=fopen(pathname,"w+"))==NULL)//打开文件 没有就创建
    {
        printf("can not creat file!\n");
    }

    fprintf(fp,"hello the first created txt! successed!!!");
    fclose(fp);
}

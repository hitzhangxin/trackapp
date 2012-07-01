#include<time.h>
#include<sys/types.h>
#include "gloable.h"

int mkdirectory () {
    if(access("trace",0)==-1)//access函数查看是不是存在
    {
        if (mkdir("trace",0777))//如果不存在就用mkdir函数来创建
        {
            printf("creat file failed!!!");
        }
    }
    pathname[0]='t'; pathname[1]='r';
    pathname[2]='a'; pathname[3]='c';
    pathname[4]='e'; pathname[5]='/';
    pathname[6]='/';
    return 0;
}    

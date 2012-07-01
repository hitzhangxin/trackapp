#include <sys/stat.h>
#include<stdio.h>
#include<time.h>
#include<sys/types.h>

char pathname[100];

struct node {
    char x; //经度
    char y; //纬度
    struct node *next;//指向下一节点的指针 
};
struct trace {
    int freq;
    struct node* head;
};

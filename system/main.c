#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include "gloable.h"

int main() {

    struct trace *trace = (struct trace*)malloc(sizeof(struct trace)); 
    get_trace(trace);
    struct node *p1 = trace->head;
    struct node *p2 = trace->head->next;

    //在压缩之前的trace内容如下
    printf("before delete the similar nodes:\n");
    while (p1) {
        printf("(%c , %c) ", p1->x, p1->y);
        p1 = p1->next;
    }

    p1 = trace->head;
    // 处理冗余数据，压缩存储
    while (p2) {
        if( (((int)(p2->x-'0') -(int) (p1->x-'0'))*((int)(p2->x-'0') -(int) (p1->x-'0')) + ((int)(p2->y-'0') - (int)(p1->y-'0'))*((int)(p2->y-'0') - (int)(p1->y-'0'))) < 3) {
            p1->next = p2->next;
            p2 = p1->next;
        } else {
            p1 = p2;
            p2 = p2->next;
        }
    }

    //打印压缩后的trace内容
    printf("\nafter process \n");
    p1 = trace->head;
    while(p1){
        printf("(%c , %c) ", p1->x, p1->y);
        p1 = p1->next;
    }
    printf("\n");
    put_trace(trace); 

    p1 = trace->head;
    while(p1){
	p2 = p1;
	p1 = p1->next;
	free(p2);
    }
    return 0;
}

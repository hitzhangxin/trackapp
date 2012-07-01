#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include "gloable.h"

void get_trace(struct trace *trace){
    char trace_data[1024];
    struct node *tail = NULL;
    int fd;
    int i = 0; 
    fd = open("gps.txt", O_RDONLY);
    read(fd, trace_data, 1024);
    //从GPS数据中提出所需信息，并存入trace所指的链表
    while (trace_data[i] >= '0' && trace_data[i] <= '9') {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->x = trace_data[i];
	i+=2;
        tmp->y = trace_data[i];
	i+=2;   
        tmp->next = NULL;

        if(tail){
            tail->next = tmp;
	}else 
	    trace->head = tmp;
        tail = tmp;
    }
    trace->freq++;
//    close(fd);
}

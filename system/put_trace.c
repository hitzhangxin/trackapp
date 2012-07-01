#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include "gloable.h"

void put_trace(struct trace *trace){
    mk_trace_file();
    char trace_data[1024];
    struct node *tail = NULL;
    struct node *tmp = trace->head;
    int fd;
    int i = 0; 
    fd = open("track.txt", O_WRONLY);
    //将track中信息存入trace所在文件
    while (tmp) {
        trace_data[i++] = tmp->x;
        trace_data[i++] = ',';
        trace_data[i++] = tmp->y;
        trace_data[i++] = ';';
	tmp = tmp->next;
    }
    trace_data[i] = '\0';
    write(fd, trace_data, i);
    close(fd);
}

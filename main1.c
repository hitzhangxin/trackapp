
#include <stdio.h>
#include <stdlib.h>

typedef struct node1 {
    double x; //经度
    double y; //纬度
    double timer; //时间

} footprint;

typedef struct node {
    int yejiedian; //是否是叶节点，0不是，1是
    int x1; //坐标
    int x2;
    int y1;
    int y2;
    int z1;
    int z2;
    int count; //结点个数
    int lchile; //左儿子
    int rchile; //右儿子
    footprint table[10]; //存的节点
} rtree;

rtree rr[16];
int nodecount = 0; //总的节点个数

void inputnode();
void gettrack();
void deletetrack();
int check(double x, double y, double z, int a, int b, int c, int d, int e, int f);

int main(int argc, char** argv) {
    struct node1 tmp; //点的数据结构
    int choose; //菜单变量
    int gen = 0;
    int tempgen = 0;
    int temprt = 0;
    rr[temprt].yejiedian = 1; //初始化
    rr[temprt].x1 = 0;
    rr[temprt].x2 = 0;
    rr[temprt].y1 = 0;
    rr[temprt].y2 = 0;
    rr[temprt].z1 = 0;
    rr[temprt].z2 = 0;
    rr[temprt].count = 0;
    rr[temprt].lchile = 0;
    rr[temprt].rchile = 0;
    while (1) {//菜单栏

        printf("1: input the track\n");
        printf("2: find the track\n");
        printf("3: delete the track\n");
        printf("4: exit\n");
        printf("please input a choose:");
        scanf("%d", &choose);
        if (choose == 1) {

            scanf("%lf", &tmp.x);
            scanf("%lf", &tmp.y);
            scanf("%lf", &tmp.timer);
            if (nodecount == 0) {//第一个节点
                rr[temprt].x1 = (int) tmp.x;
                rr[temprt].x2 = (int) tmp.x + 1;
                rr[temprt].y1 = (int) tmp.y;
                rr[temprt].y2 = (int) tmp.y + 1;
                rr[temprt].z1 = (int) tmp.timer;
                rr[temprt].z2 = (int) tmp.timer + 1;
                rr[temprt].table[rr[temprt].count].timer = tmp.timer;
                rr[temprt].table[rr[temprt].count].x = tmp.x;
                rr[temprt].table[rr[temprt].count].y = tmp.y;
                rr[temprt].count++;
                nodecount++;
            } else if (rr[temprt].yejiedian == 1 && check(tmp.x, tmp.y, tmp.timer, rr[temprt].x1, rr[temprt].x2, rr[temprt].y1, rr[temprt].y2, rr[temprt].z1, rr[temprt].z2) == 1) {
                rr[temprt].table[rr[temprt].count].timer = tmp.timer;//在范围里并且是叶节点继续添加节点
                rr[temprt].table[rr[temprt].count].x = tmp.x;
                rr[temprt].table[rr[temprt].count].y = tmp.y;
                rr[temprt].count++;
            } else if (rr[temprt].yejiedian == 1 && check(tmp.x, tmp.y, tmp.timer, rr[temprt].x1, rr[temprt].x2, rr[temprt].y1, rr[temprt].y2, rr[temprt].z1, rr[temprt].z2) == 0) {
                tempgen = nodecount + 1;//不在范围里并且是叶节点
            }
        } else if (choose == 2) {

        } else if (choose == 3) {

        } else if (choose == 4) {
            return 0;
        }
    }
    return (EXIT_SUCCESS);
}

void inputnode() {

}

void gettrack() {

}

void deletetrack() {

}

int check(double x, double y, double z, int a, int b, int c, int d, int e, int f) {
    if (x >= (double) a && x <= (double) b && y >= (double) c && y <= (double) d && z >= (double) e && z <= (double) f) {
        return 1;
    }
    return 0;
}

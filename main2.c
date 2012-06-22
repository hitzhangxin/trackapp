#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    double x; //经度
    double y; //纬度
    double timer; //时间

} footprint;

void* suoyin[10][10][10] = {NULL};
int count[10][10][10] = {0};
void* newfootprint();

int main(int argc, char** argv) {
    int choose;
    footprint temp;
    double* tmp = NULL;
    while (1) {//菜单栏

        printf("1: input the track\n");
        printf("2: find the track\n");
        printf("3: delete the track\n");
        printf("4: exit\n");
        printf("please input a choose:");
        scanf("%d", &choose);
        if (choose == 1) {
            scanf("%lf", &temp.x);
            scanf("%lf", &temp.y);
            scanf("%lf", &temp.timer);
            if (temp.x < 0 || temp.x > 10 || temp.y < 0 || temp.y > 10 || temp.timer < 0 || temp.timer > 10) {
                printf("it is over!\n");
                continue;
            } else if (count[(int) temp.x][(int) temp.y][(int) temp.timer] == 0) {
                suoyin[(int) temp.x][(int) temp.y][(int) temp.timer] = newfootprint();
                tmp = suoyin[(int) temp.x][(int) temp.y][(int) temp.timer];
                *(tmp) = temp.x;
                *(tmp + 1) = temp.y;
                *(tmp + 2) = temp.timer;
                count[(int) temp.x][(int) temp.y][(int) temp.timer] = 1;
            } else if ((count[(int) temp.x][(int) temp.y][(int) temp.timer]) % 10 == 0) {

            }
        } else if (choose == 2) {

        } else if (choose == 3) {

        } else if (choose == 4) {
            return 0;
        }
    }
    return (EXIT_SUCCESS);
}

void* newfootprint() {
    return malloc(sizeof (double) * 30);
}

void changesize(){

    malloc();
}
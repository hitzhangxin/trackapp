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
    int i = 0;
    int j = 0;
    int k = 0;
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
            if (temp.x < 0 || temp.x > 10) {
                printf("it is over!\n");
                continue;
            }
            scanf("%lf", &temp.y);
            if (temp.y < 0 || temp.y > 10) {
                printf("it is over!\n");
                continue;
            }
            scanf("%lf", &temp.timer);
            if (temp.timer < 0 || temp.timer > 10) {
                printf("it is over!\n");
                continue;
            }
            if (count[(int) temp.x][(int) temp.y][(int) temp.timer] == 0) {
                suoyin[(int) temp.x][(int) temp.y][(int) temp.timer] = newfootprint();
                tmp = suoyin[(int) temp.x][(int) temp.y][(int) temp.timer];
                *(tmp) = temp.x;
                *(tmp + 1) = temp.y;
                *(tmp + 2) = temp.timer;
                count[(int) temp.x][(int) temp.y][(int) temp.timer] = 1;
            } else if ((count[(int) temp.x][(int) temp.y][(int) temp.timer]) == 10) {
                printf("it is man!!\n");
            } else if ((count[(int) temp.x][(int) temp.y][(int) temp.timer]) < 10) {
                tmp = suoyin[(int) temp.x][(int) temp.y][(int) temp.timer];
                *(tmp + 3 * count[(int) temp.x][(int) temp.y][(int) temp.timer]) = temp.x;
                *(tmp + 3 * count[(int) temp.x][(int) temp.y][(int) temp.timer] + 1) = temp.y;
                *(tmp + 3 * count[(int) temp.x][(int) temp.y][(int) temp.timer] + 2) = temp.timer;
                count[(int) temp.x][(int) temp.y][(int) temp.timer]++;
            }
        } else if (choose == 2) {
            int choose1;
            int temx;
            int temy;
            int temtimer;
            printf("1: x,2: y,3: timer");
            scanf("%d", &choose1);
            if (choose1 == 1) {
                scanf("%d", &temx);
                for (i = 0, j = 0; i < 0, j < 10; i++, j++) {
                    if (count[temx][i][j] != 0) {
                        tmp = suoyin[temx][i][j];
                        for (k = 0; k < count[temx][i][j]; k++) {
                            printf("x: %lf,y: %lf,timer: %lf\n", *(tmp + k * 3), *(tmp + k * 3 + 1), *(tmp + k * 3 + 2));
                        }
                    }
                }
            } else if (choose1 == 2) {
                scanf("%d", &temy);
                for (i = 0, j = 0; i < 0, j < 10; i++, j++) {
                    if (count[i][temy][j] != 0) {
                        tmp = suoyin[i][temy][j];
                        for (k = 0; k < count[i][temy][j]; k++) {
                            printf("x: %lf,y: %lf,timer: %lf\n", *(tmp + k * 3), *(tmp + k * 3 + 1), *(tmp + k * 3 + 2));
                        }
                    }
                }
            } else if (choose1 == 3) {
                scanf("%d", &temtimer);
                for (i = 0, j = 0; i < 0, j < 10; i++, j++) {
                    if (count[i][j][temtimer] != 0) {
                        tmp = suoyin[i][j][temtimer];
                        for (k = 0; k < count[i][j][temtimer]; k++) {
                            printf("x: %lf,y: %lf,timer: %lf\n", *(tmp + k * 3), *(tmp + k * 3 + 1), *(tmp + k * 3 + 2));
                        }
                    }
                }
            }
        } else if (choose == 3) {
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 10; j++) {
                    for (k = 0; k < 10; k++) {
                        count[i][j][k] = 0;
                        suoyin[i][j][k] = NULL;
                    }
                }
            }
        } else if (choose == 4) {
            return 0;
        }
    }
    return (EXIT_SUCCESS);
}

void* newfootprint() {
    return malloc(sizeof (double) * 30);
}

void changesize() {


}
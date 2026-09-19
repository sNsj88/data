#include <stdio.h>
#define ROUTE_COUNT 13

char routes[ROUTE_COUNT][10] = {
    "A->B", "A->C", "A->D", "A->E",
    "B->A", "B->C", "B->D",
    "C->A", "C->B", "C->D", "C->E",
    "D->A", "D->B"
};

int conflict[ROUTE_COUNT][ROUTE_COUNT] = {0};
int color[ROUTE_COUNT];

void colorGraph()
{
    int i, j;
    for(i = 0; i < ROUTE_COUNT; i++)
    {
        int usedColor[ROUTE_COUNT] = {0};

        for(j = 0; j < ROUTE_COUNT; j++)
        {
            if(conflict[i][j] == 1 && color[j] != -1)
            {
                usedColor[color[j]] = 1;
            }
        }

        int c = 0;
        while(usedColor[c] == 1)
        {
            c++;
        }
        color[i] = c;
    }
}

int main()
{
    int i;
    for(i = 0; i < ROUTE_COUNT; i++)
    {
        color[i] = -1;
    }

    conflict[2][12] = 1;
    conflict[12][2] = 1;

    conflict[0][6] = 1; conflict[6][0] = 1;
    conflict[1][7] = 1; conflict[7][1] = 1;
    conflict[3][5] = 1; conflict[5][3] = 1;
    conflict[4][10] = 1; conflict[10][4] = 1;
    conflict[8][11] = 1; conflict[11][8] = 1;

    colorGraph();

    printf("====五岔路口交通灯分组（图着色结果）====\n");
    for(int c = 0; c < ROUTE_COUNT; c++)
    {
        int hasItem = 0;
        printf("相位%d绿灯：", c+1);
        for(i = 0; i < ROUTE_COUNT; i++)
        {
            if(color[i] == c)
            {
                printf("%s  ", routes[i]);
                hasItem = 1;
            }
        }
        if(hasItem == 1)
            printf("\n");
    }
    printf("\n说明：同一相位的路线无冲突，可以同时放行；不同相位交替放行。\n");
    return 0;
}

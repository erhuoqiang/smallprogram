#include <stdio.h>
#include <limits.h>
#include <string.h>

const int n = 6;
int map[n][n];

int dijk(int s, int e)
{
    int dis[n];
    int used[n] = {0};
    int min, next;
    memset(dis, 255, sizeof(dis));//把所有未更新的dis[]设置成-1

    dis[s] = 0;                    //从s开始

    for (int i=1; i<n; ++i)
    {
        min = INT_MAX;
        for (int j=1; j<n; ++j)
        {
            if (!used[j] && dis[j]!=-1 && dis[j]<min)
            {
                min = dis[j];
                next = j;
            }
        }
        if (min != INT_MAX)
        {
            used[next] = 1;
            for (int j=1; j<n; ++j)
            {
                if (!used[j] && map[next][j]!=-1 &&
                        (dis[j]>map[next][j]+dis[next] || dis[j]==-1))
                {
                    dis[j] = map[next][j] + dis[next];
                }
            }
        }
    }
    return dis[e];
}


int main()
{
    for (int i=1; i<n; ++i)
    {
        for (int j=1; j<n; ++j)
        {
            map[i][j] = -1;
        }
    }

    map[1][2] = 10;
    map[1][4] = 30;
    map[1][5] = 100;
    map[2][3] = 50;
    map[3][5] = 10;
    map[4][3] = 20;
    map[4][5] = 60;
    printf("%d %d %d %d %d %d\n", dijk(1, 5), dijk(2, 3), dijk(1, 5), dijk(4, 5), dijk(1, 2), dijk(2, 4));


    return 0;
}

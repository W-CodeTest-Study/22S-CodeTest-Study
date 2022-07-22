﻿#include <queue>
#include <stdio.h>
using namespace std;
int map[20][20] = {};
int time = 0, map_size, shark_size = 2, eaten_fish = 0, current_X, current_Y;
int dx[] = { 0,-1,1,0 }; //BFS를 사방으로 쉽게 하는 법
int dy[] = { -1,0,0,1 };
queue<pair<int, int>> q;
int check(int x, int y)
{
    int movement = 0, i, tx = 20, ty = 20, block = 0;
    q = queue<pair<int, int>>();
    bool hb[20][20] = {}; //이미 간 곳을 체크하기 위한 배열
    hb[x][y] = 1;
    q.push({ x,y });
    while (!q.empty())
    {
        int s = q.size();
        movement++;
        while (s--)
        {
            pair<int, int> a = q.front();
            q.pop();
            for (i = 0; i < 4; ++i)
            {
                int qx = a.first + dx[i];
                int qy = a.second + dy[i];
                if (qx < 0 || qx >= map_size || qy < 0 || qy >= map_size) continue; //배열 밖이면 넘어감
                if (0 < map[qx][qy] && map[qx][qy] < shark_size)
                {
                    if (qy < ty) //BFS 세부 메커니즘
                    {
                        ty = qy;
                        tx = qx;
                    }
                    if (qy == ty && qx < tx)
                        tx = qx;
                }
                if (!hb[qx][qy] && (map[qx][qy] == 0 || map[qx][qy] == shark_size))
                {
                    hb[qx][qy] = 1;
                    block = 1;
                    q.push({ qx, qy });
                }
            }
        }
        if (tx != 20 && ty != 20)
        {
            eaten_fish++;
            map[tx][ty] = 0;
            current_X = tx;
            current_Y = ty;
            time += movement;
            tx = ty = 20;
            return 1;
        }
        if (!block)
            return 0;
        block = 0;
    }
    return 1;
}
int main()
{
    int i, j, p;
    scanf("%d", &map_size);
    for (i = 0; i < map_size; ++i)
        for (j = 0; j < map_size; ++j)
        {
            scanf("%d", &map[j][i]);
            if (map[j][i] == 9) //9는 상어 처음 위치
            {
                current_X = j;
                current_Y = i;
                map[j][i] = 0;
            }
        }
    while (1)
    {
        p = 0;
        for (i = 0; i < map_size; ++i)
            for (j = 0; j < map_size; ++j)
                if (map[j][i] < shark_size && map[j][i] > 0)
                    p = 1; //p가 1이면 아직 먹을 물고기가 있다는 뜻
        if (!p)
        {
            printf("%d", time);
            return 0;
        }
        if (!check(current_X, current_Y)) //current_X, current_Y는 상어의 위치
        {
            printf("%d", time);
            return 0;
        }
        if (eaten_fish == shark_size)
        {
            shark_size++;
            eaten_fish = 0;
        }
    }
}
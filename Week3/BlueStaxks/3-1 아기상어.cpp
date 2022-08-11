#include <queue> //queue를 쓰기 위한 헤더
#include <stdio.h>
using namespace std; //C++ 명령어를 위한 코드
int map[20][20] = {};
int time = 0, map_size, shark_size = 2, eaten_fish = 0, current_X, current_Y;
int dx[4] = { 0,-1,1,0 }; //BFS를 사방으로 쉽게 하는 법
int dy[4] = { -1,0,0,1 };
queue<pair<int, int>> q; //pair가 인자가 되는 queue 선언, 이름 : q
int check(int x, int y)
{
    int movement = 0, i, tx = 20, ty = 20;
    q = queue<pair<int, int>>(); //q 초기화
    bool hb[20][20] = {}, moved = false; //이미 간 곳을 체크하기 위한 배열
    hb[x][y] = 1;
    q.push({ x,y }); //x와 y를 pair로 q에 push
    while (!q.empty()) //q가 비어있지 않는 동안
    {
        int s = q.size(); //s = q에 남아있는 pair 개수
        movement++;
        while (s--)
        {
            pair<int, int> a = q.front(); //int a 하듯이 pair<int,int> a //q.front()는 q의 가장 앞 인자를 참조함
            q.pop(); //q를 pop함(가장 앞 인자 삭제)
            for (i = 0; i < 4; ++i)
            {
                int qx = a.first + dx[i];    //a의 앞 정수 + dx[i]라는 뜻 //x,y를 pair했다면 first 인자는 x, second 인자는 y가 됨
                int qy = a.second + dy[i];
                if (qx < 0 || qx >= map_size || qy < 0 || qy >= map_size) continue; //배열 밖이면 넘어감
                if (0 < map[qx][qy] && map[qx][qy] < shark_size) //이 조건을 만족하면 이미 가본 곳일 수가 없음
                {
                    if (qy < ty) //더 높으면 (y는 수가 작을 수록 높은 것)
                    {
                        ty = qy;
                        tx = qx;
                    }
                    if (qy == ty && qx < tx) //높이가 같으면 왼쪽꺼
                        tx = qx;
                }
                if (!hb[qx][qy] && (map[qx][qy] == 0 || map[qx][qy] == shark_size)) //물고기를 먹은 것은 아니고 그냥 움직이는 것
                {
                    hb[qx][qy] = 1;
                    moved = true;
                    q.push({ qx, qy });
                }
            }
        }
        if (tx != 20 && ty != 20) //tx ty는 상어의 이번 턴 최종 위치가 됨 //그리고 그 값이 20이 아니라면 물고기를 먹었다는 뜻임
        {
            eaten_fish++;
            map[tx][ty] = 0;
            current_X = tx;
            current_Y = ty;
            time += movement;
            tx = ty = 20; //tx ty를 20으로 설정하면 가장 오른쪽 아래 +1이 됨. 지도 밖을 벗어나는 것
            return 1;
        }
        if (!moved) //못움직였다면 끝
            return 0;
        moved = false;
    }
}
int main()
{
    int i, j;
    bool p;
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
        p = false;
        for (i = 0; i < map_size; ++i)
            for (j = 0; j < map_size; ++j)
                if (map[j][i] < shark_size && map[j][i] > 0)
                    p = true; //p가 1이면 아직 먹을 물고기가 있다는 뜻
        if (!p || !check(current_X, current_Y)) //current_X, current_Y는 상어의 위치
        {
            printf("%d", time);
            return 0;
        }
        if (eaten_fish == shark_size) //자기만큼 먹으면 커짐
        {
            shark_size++;
            eaten_fish = 0;
        }
    }
}
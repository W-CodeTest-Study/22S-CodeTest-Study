/*

	---//전역 변수 설정

	지도 배열 선언(20 * 20 사이즈, 정수형, 이름 : map, 초기값 : 전부 0)
	시간 변수 선언(정수형, 이름 : time, 초기값 : 0)
	지도 크기 변수 선언(정수형, 이름 : map_size)
	상어 크기 변수 선언(정수형, 이름 : shark_size, 초기값 : 2)
	먹은 고기 변수 선언(정수형, 이름 : eaten_fish, 초기값 : 0)
	상어의 X 위치 변수 선언(정수형, 이름 : current_X)
	상어의 Y 위치 변수 선언(정수형, 이름 : current_Y)
	쉬운 BFS를 위한 X축 파라미터 배열 선언(4 사이즈, 이름 : dx, 초기값 : {0,-1,1,0} )
	쉬운 BFS를 위한 Y축 파라미터 배열 선언(4 사이즈, 이름 : dy, 초기값 : {-1,0,0,1} )
    Queue 선언(정수 2개를 세트로 입력하는 pair형, 이름 : q)

	
	---//check 함수(정수 반환, int x와 int y를 매개변수로 입력받음)   //프로그램이 시작될 때 85줄의 main함수가 가장 먼저 시작됨 //check함수는 불릴 때만 실행됨

	움직인 횟수 변수 선언(정수형, 이름 : movement, 초기값 : 0)
	for문을 위한 변수 선언(정수형, 이름 : i)
	가장 위 왼쪽 먹이를 선택하기 위해 만드는 X축 변수 선언(정수형, 이름 : tx, 초기값 : 20)  //지도가 0~19까지 있으므로 20으로 설정
	가장 위 왼쪽 먹이를 선택하기 위해 만드는 Y축 변수 선언(정수형, 이름 : ty, 초기값 : 20)  //지도가 0~19까지 있으므로 20으로 설정
	움직였나 안움직였나를 체크하는 변수 선언(bool형, 이름 : moved, 초기값 : false)

	q를 초기화
	지도에서 이미 간 곳을 체크하기 위한 배열 선언(20 * 20 사이즈, bool형, 이름 : hb, 초기값 : 전부 false)

	hb[x][y]에 true 입력
	q에 x,y를 pair로 push

	while (q가 비어있지 않는 동안)
	{
		q 크기 변수 선언(정수형, 이름 : s, 초기값 : q의 크기)
		movement에 1 추가
		while (s가 0보다 클 동안)
		{
			s에 1 감소
			pair 변수 선언(둘 다 정수형, 이름 : a, 초기값 : q의 가장 앞 pair)
			q의 가장 앞 pair를 pop
			for(i = 0, i < 4; ++i) //i가 0부터 3이 될 때까지 반복하고 i는 각 반복때 마다 1씩 증가
			{
				BFS용 임시 X축 변수 선언(정수형, 이름 : qx, 초기값 : a의 앞 정수 + dx의 i번째 정수)
				BFS용 임시 Y축 변수 선언(정수형, 이름 : qy, 초기값 : a의 뒷 정수 + dy의 i번째 정수)

				if(qx < 0 이거나 qx >= map_size 이거나 qy < 0 이거나 qy >= map_size) //qx와 qy가 지도 밖으로 나가는 것을 방지함
					여기서 바로 반복시작 //만약 i가 1일 때 이 if문에 걸리면 i가 2가된 상태로 42줄부터 다시 시작 
				
				if(0 < map[qx][qy] 이면서 map[qx][qy] < shark_size) //이 if문에 걸리면 map[qx][qy]위치에 상어가 먹을 수 있는 먹이가 있는 것
				{
					if(qy < ty) //더 높으면 높은 것 선택 (y값은 작을 수록 위쪽임)
					{
						ty에 qy값 입력
						tx에 qx값 입력
					}
					if(qy와 ty가 같으면서 qx가 tx보다 작으면) //높이가 같을 땐 왼쪽 먹이를 선택해야함
						tx에 qx값 입력 //y는 이미 같으므로 입력 불필요
				}

				if((hb[qx][qy]가 false) 이면서 ((map[qx][qy]가 0) 이거나 (map[qx][qy]가 shark_size와 같음))) //이러면 지나갈 수 있는 곳이라는 뜻
				{
					hb[qx][qy]에 true 입력
					moved에 true 입력
					q에 qx,qy를 pair로 push
				}
			}
		}

		if(tx가 20이 아니면서 ty도 20이 아님)
		{
			eaten_fish에 1 추가
			map[tx][ty]에 0 입력 //먹이 먹은 곳은 0으로 초기화
			current_X에 tx 입력 //상어의 X 위치 업데이트
			current_Y에 ty 입력 //상어의 Y 위치 업데이트
			time 값에 movement 값 추가 //상어의 생존 시간 추가 //34줄에서 movement만 늘리고 time을 늘리지 않는 이유는, 먹이가 없을 경우 움직일 수 없지만 먹이가 없는 것을 알기 위해 움직여야 하기 때문
            tx와 ty값 모두에 20 입력
			1을 반환하고 함수 종료
		}
		if(moved가 false)
			0을 반환하고 함수 종료
		moved에 false 입력
	}



	---//main 함수(정수 반환)

	for문을 위한 변수 선언(정수형, 이름 : i)
	for문을 위한 변수 선언(정수형, 이름 : j)
	먹을 물고기가 있는 지 나타내는 변수 선언(bool형, 이름 : p)

	map_size값 입력 받기(정수형)

	for (i = 0; i < map_size; ++i)
        for (j = 0; j < map_size; ++j)
        {
			map[j][i]값 입력 받기(정수형)
            if (map[j][i]이 9와 같음) //9는 상어 처음 위치
            {
                current_X에 j 입력;
                current_Y에 i 입력;
                map[j][i]에 0 입력; //0으로 초기화
            }
        }

	(무한 반복문)
    {
        p에 false 입력;
        for (i = 0; i < map_size; ++i)
            for (j = 0; j < map_size; ++j)
                if (map[j][i] < shark_size 이면서 map[j][i] > 0)
                    p에 true 입력; //p가 ture면 아직 먹을 물고기가 있다는 뜻
        if ((p가 false) 이거나 (함수 check(current_X, current_Y)의 반환값이 0))
        {
			time 출력
            0을 반환하고 함수 종료
        }
        if (eaten_fish가 shark_size와 같음) //자기만큼 먹으면 커짐
        {
            shark_size에 1 추가
            eaten_fish에 0 입력;
        }
    }
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

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

*/
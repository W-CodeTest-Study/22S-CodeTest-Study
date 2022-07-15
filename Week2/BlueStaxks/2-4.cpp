#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int, int> m;  //긴 배열에 겹치지 않게 트럭을 배치하는 느낌
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int tc = 0, w = 0, i, p = 0, vp = 0;
    queue<int> v;
    for (i = bridge_length + 1; ;)
    {
        if (tc < bridge_length && w + truck_weights[p] <= weight) //트럭 올리기 가능
        {
            if (p == truck_weights.size() - 1)
                return i;
            m[i] = truck_weights[p];
            w += truck_weights[p]; //총 무게
            tc++; //다리 위 트럭 수
            v.push(i); //m에서의 트럭 위치
            i++;
            p++;
        }
        else
        {
            w -= m[v.front()];
            i = v.front() + bridge_length;
            v.pop();
            tc--;
        }
        if(!v.empty())
            while (v.front() + bridge_length <= i) //다리 길이보다 앞에 있는 애들 없애기
            {
                w -= m[v.front()];
                v.pop();
                tc--;
                if (v.empty())
                    break;
            }
    }   
}

#include <iostream>
int main()
{
    vector<int> v(5);
    v[0] = 7; v[1] = 4; v[2] = 5; v[3] = 4; v[4] = 5;
    vector<int> v1(4, 1);
    vector<int> v2(10, 10);
    vector<int> v3(4);
    v3[0] = 7; v3[1] = 4; v3[2] = 5; v3[3] = 6;
    vector<int> v4(9, 1);
    v4[0] = v4[1] = v4[2] = v4[3] = 2;
    //cout << solution(2, 10, v3); //8
    //cout << solution(100, 100, v2);
    //cout << solution(4, 2, v1); //10
    //cout << solution(2, 10, v); //8
    cout << solution(5, 5, v4);
}
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int, int> m;  //긴 배열에 겹치지 않게 트럭을 배치하는 느낌
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int tc = 0, w = 0, i, p = 0, vp = 0;
    queue<int> v;
    for (i = bridge_length + 1; ;) //i는 시간을 뜻하고 다리를 다 건너는 시간으로 맞춰져 있음
    {
        if (tc < bridge_length && w + truck_weights[p] <= weight) //트럭 올리기 가능
        {
            if (p == truck_weights.size() - 1) //마지막 트럭이 들어오면 i 리턴 //어차피 마지막 트럭에 의해 최종 시간이 결정됨
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
            i = v.front() + bridge_length; //트럭을 올릴 수 없다면 다리에 있는 트럭을 빼야됨. 빼자마자 들어가야 되기 때문에 그에 맞는 i 설정
            v.pop();
            tc--;
        }
        if(!v.empty())
            while (v.front() + bridge_length <= i) //다리 길이보다 앞에 있는 애들 없애기 == 이미 다리 건넌 애들 없애기
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
    cout << solution(2, 10, v); //8
}
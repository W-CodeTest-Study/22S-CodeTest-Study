#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int, int> m;  //긴 배열에 겹치지 않게 트럭을 배치하는 느낌
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int current_truck_count = 0, current_weight = 0, time, truck_index = 0;
    queue<int> q;
    for (time = bridge_length + 1; ;) //time은 다리를 다 건너는 시간으로 맞춰져 있음
    {
        if (current_truck_count < bridge_length && current_weight + truck_weights[truck_index] <= weight) //트럭 올리기 가능
        {
            if (truck_index == truck_weights.size() - 1) //마지막 트럭이 들어오면 리턴 //어차피 마지막 트럭에 의해 최종 시간이 결정됨
                return time;
            m[time] = truck_weights[truck_index];
            current_weight += truck_weights[truck_index]; //총 무게
            current_truck_count++; //다리 위 트럭 수
            q.push(time); //m에서의 트럭 위치를 Queue에 입력
            time++; //트럭 들어갔으니 1초 뒤로
            truck_index++; //다음 트럭으로
        }
        else
        {
            current_weight -= m[q.front()];
            time = q.front() + bridge_length; //트럭을 올릴 수 없다면 다리에 있는 트럭을 빼야됨. 빼자마자 들어가야 되기 때문에 그에 맞는 time 설정
            q.pop();
            current_truck_count--;
        }
        if(!q.empty())
            while (q.front() + bridge_length <= time) //다리 길이보다 앞에 있는 애들 없애기 == 이미 다리 건넌 애들 없애기
            {
                current_weight -= m[q.front()];
                q.pop();
                current_truck_count--;
                if (q.empty())
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

/*

    m map : key = time, value = 트럭 무게   //m이라는 배열이 시간을 key로 해서 길게 있고 그 위에 트럭을 적절히 배치한 뒤 다리를 움직이는 것이라 생각하면 쉬움

    time = brodge_length + 1
    while(1)
        만약 다리에 다음 트럭이 올라갈 수 있다면
        {
            만약 다음 트럭이 마지막 트럭이라면
                time 리턴 //유일한 종료 조건

            Queue에 그 트럭의 다리 통과(끝) 시간 push
            트럭 들어갔으니 time 1추가
        }
        else //여기로 왔다는 것은 다리에 트럭을 못올린다는 거니까 다리에서 트럭을 빼야됨
        {
            Queue 가장 앞 트럭 빼기
            time 에 가장 앞 트럭의 다리 통과(끝) 시간 입력
        }
        이미 다리를 다 통과한 트럭을 Queue에서 제거

*/
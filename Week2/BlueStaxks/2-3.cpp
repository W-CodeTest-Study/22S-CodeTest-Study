#include <string>
#include <vector>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int s = (int)speeds.size(), i, p = 0, c;
    while (1)
    {
        c = 0; //배포할 기술 개수
        if (progresses[p] >= 100)
        {
            while (progresses[p] >= 100)
            {
                c++;
                p++; //순서대로 배포해야 하기 때문에 증가만 하는 p 사용
                if (p >= s) //끝까지 다 만들면 끝
                {
                    answer.push_back(c);
                    return answer;
                }
            }
            answer.push_back(c);
        }
        for (i = p; i < s; ++i)
            progresses[i] += speeds[i]; //개발 진행
    }
}
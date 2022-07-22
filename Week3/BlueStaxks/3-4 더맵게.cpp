#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int solution(vector<int> scoville, int K)
{
    int i, a, b, count = 0;
    for (i = 0; i < scoville.size(); ++i)
        q.push(scoville[i]); // 작은 순으로 나오는 queue
    while (q.size() >= 2 && q.top() < K) //q에 최소 2개는 있어야 더 맵게 만들 수 있음
    {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a + (b * 2));
        count++;
    }
    if (q.top() < K) //불가능하면 -1
        return -1;
    return count;
}
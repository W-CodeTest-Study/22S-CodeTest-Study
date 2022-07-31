#include <vector>
#include <algorithm>
using namespace std;
vector<int> createV(vector<int> v1, vector<int> v2)
{
    vector<int> r;
    int i, j;
    for (i = 0; i < v1.size(); ++i)
        for (j = 0; j < v2.size(); ++j)
        {
            r.push_back(v1[i] + v2[j]);
            r.push_back(v1[i] - v2[j]);
            r.push_back(v2[j] - v1[i]);
            if (v1[i] && v2[j])
            {
                r.push_back(v1[i] * v2[j]); //0을 추가할 필요 없음
                r.push_back(v1[i] / v2[j]);
                r.push_back(v2[j] / v1[i]);
            }
        }
    return r;
}
int solution(int N, int number)
{
    if (N == number)   return 1; //1개
    int i, j, t;
    vector<vector<int>> v(9);
    v[1].push_back(N);
    for (i = 2; i <= 8; ++i) //i는 개수 (2면 N 2개로 만들 수 있는 수, v[2]엔 그 수들이 들어가 있는 것)
    {
        for (j = 1; j <= i / 2; ++j) //i가 5일 때를 예로 들자면 1+4, 2+3의 방법으로 5개짜리를 만들 수 있음
        {
            vector<int> vt = createV(v[j], v[i - j]);
            v[i].insert(v[i].end(), vt.begin(), vt.end());
        }
        for (j = 0, t = 0; j < i; ++j)
        {
            t *= 10;
            t += N;
        } // N이 5고 i가 3이면 555 추가
        v[i].push_back(t);
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end()); //중복 제거
        for (j = 0; j < v[i].size(); ++j)
            if (v[i][j] == number)
                return i; //있으면 i리턴
    }
    return -1; //8을 넘어가면 -1
}
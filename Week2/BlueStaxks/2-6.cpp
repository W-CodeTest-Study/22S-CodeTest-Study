#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<string>> clothes)
{
    int j, r = 1;
    string s1, s2;
    unordered_map<string, int> m;
    vector<string> v;
    for (j = 0; j < clothes.size(); ++j)
    {
        v.push_back(clothes[j][1]);
        m[clothes[j][1]]++; //옷 종류당 몇개인지 체크
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); //v는 옷 종류를 담는 배열
    for (j = 0; j < v.size(); ++j)
        r *= (m[v[j]] + 1); //경우의 수 연산
    return r - 1; //다 벗은 경우 제외 + clothes가 하나도 없을 경우 자동으로 0 리턴(r이 처음엔 1이니까)
}
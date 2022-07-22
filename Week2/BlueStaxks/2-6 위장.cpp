#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<string>> clothes)
{
    int i, r = 1;
    unordered_map<string, int> m;
    vector<string> v;
    for (i = 0; i < clothes.size(); ++i)
    {
        v.push_back(clothes[i][1]);
        m[clothes[i][1]]++; //옷 종류당 몇개인지 체크
    }
    sort(v.begin(), v.end()); //17번 줄의 중복 제거를 위해 sort가 필요함
    v.erase(unique(v.begin(), v.end()), v.end()); //v는 옷 종류를 담는 배열
    for (i = 0; i < v.size(); ++i)
        r *= (m[v[i]] + 1); //경우의 수 연산
    return r - 1; //다 벗은 경우 제외, clothes가 하나도 없을 경우 자동으로 0 리턴(r이 처음엔 1이니까)
}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int vs = 0;
vector<int> exN(string& s) //문자열에서 숫자 뽑기
{
    vector<int> v;
    int n = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            n *= 10;
            n += s[i] - '0';
        }
        else
        {
            v.push_back(n);
            n = 0;
        }
    }
    return v;
}
vector<vector<int>> check(string& s)
{
    vector<vector<int>> v(501);
    int i, p1, p2;
    string t;
    for (i = 1; i < s.length() - 1; ++i)
    {
        p1 = s.find("{", i);
        if (p1 == string::npos)    break;
        p2 = s.find("}", p1 + 1);
        i = p2;
        t = s.substr(p1 + 1, p2 - p1);
        vector<int> vt = exN(t);
        sort(vt.begin(), vt.end());
        v[vt.size()] = vt;
        vs < vt.size() ? vs = vt.size() : 0;
    }
    for (i = 500; i > vs; --i)
        v.pop_back(); //쓸데 없는 벡터 지우기
    return v;
}
vector<int> solution(string s)
{
    vector<vector<int>> v = check(s); //v[0]엔 없고 v[1]부터 있고 []안의 수가 사이즈임 //1개짜리, 2개짜리를 봤을 때 2개짜리에서 새로 생긴 수가 더 나중에 나오는 수임
    vector<int> r;
    vector<int>::iterator it;
    int i;
    r.push_back(v[1][0]);
    for (i = 1; i < vs; ++i)
    {
        vector<int> t(v[i + 1].size() + v[i].size());
        it = set_difference(v[i + 1].begin(), v[i + 1].end(), v[i].begin(), v[i].end(), t.begin()); //이러면 t에 v[i+1],v[i]의 차집합이 들어감
        r.push_back(t[0]); //차집합의 원소 개수는 어차피 1개니까 t를 resize하지 않고 [0]으로 바로 참조
    }
    return r;
}


#include <iostream>
int main()
{
    vector<int> r = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (int i = 0; i < r.size(); ++i)
        printf("%d ", r[i]);
    return 0;
}
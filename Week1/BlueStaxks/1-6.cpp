#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(int n, vector<int> info)
{
    int m[11];
    int i, j, c, ma = 0, s1, s2;
    vector<int> r(11, 0);
    for (i = 0; i < 10; ++i)
        m[i] = info[i] + 1; //1점만 높아도 뺏어갈 수 있음
    m[10] = 0; //0점은 먹으나 안먹으나 다를 게 없으므로 쓰레기통으로 사용
    for (i = 11; i >= 1; --i)
    {
        vector<bool> t(11, false);
        for (j = 0; j < i; ++j)
            t[j] = true;
        do {
            c = s1 = s2 = 0;
            for (j = 0; j < 11; ++j)
                if (t[j])
                    c += m[j]; //c는 총 발사 횟수
            if (c <= n) //n보다 커버리면 안됨(작아도 0점에 버리면 되므로 괜춘)
            {
                for (j = 0; j < 10; ++j) //0은 생각 안하므로 10번만
                {
                    if (info[j] < m[j] * t[j]) //t는 0아니면 1이기에 곱한 값 더하면 깔끔하게 딱 됨
                        s2 += 10 - j;
                    if (info[j] >= m[j] * t[j] && info[j]) //억울한 라이언 ㅠㅠ
                        s1 += 10 - j;
                }
                if (s2 - s1 > ma) //점수차 최대일 시
                {
                    ma = s2 - s1;
                    for (j = 0; j < 10; ++j)
                        r[j] = t[j] * m[j]; 
                    r[10] = n - c; //남은거 다 담기
                }
            }
        } while (prev_permutation(t.begin(), t.end())); //앞쪽에 true가 몰리므로 prev를 씀
    }
    if (ma <= 0) //이러면 못 이기는거임
    {
        vector<int> r0(1,-1);
        return r0;
    }
    return r;
}


int main()
{
    vector<int> v(11, 0);
    vector<int> s;
    v[8] = v[10] = 3;
    v[9] = 4;
    s = solution(10, v);
    for (int i = 0; i < s.size(); ++i)
        printf("%d ", s[i]);
    return 0;
}
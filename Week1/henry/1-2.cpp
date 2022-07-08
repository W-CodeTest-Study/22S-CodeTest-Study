#include <stdio.h>

#include <string>
#include <math.h>
#include <vector>
using namespace std;
int solution(string dartResult)
{
    int i = 0, s = (int)dartResult.length();
    dartResult += '('; //문자열 bad_excess 방지용 문자 추가(i+1 이런 식으로 탐색할 때 문제가 없어짐)
    int m = 1, d = 1, c = 0;
    vector<int> v;
    for (i = 0; i < s; ++i)
    {
        if (dartResult[i] == '#')
        {
            d *= -1;
            v.push_back(c * d * m);
            d = m = 1;
        }
        else if (dartResult[i] == '*')
        {
            m *= 2;
            v.push_back(c * d * m);
            d = m = 1;
            if (v.size()>1)
                v[v.size() - 2] *= 2;
        }
        else if ('0' <= dartResult[i] && dartResult[i] <= '9')
        {
            if (i && dartResult[i - 1] != '*' && dartResult[i - 1] != '#')
                v.push_back(c * d * m);
            c = dartResult[i] - '0';
            if (c == 1 && dartResult[i + 1] - '0' == 0)
            {
                c = 10;
                i++;
            }
        }
        else if (dartResult[i] == 'D') //S는 아무것도 안해도 됨
            c = pow(c, 2);
        else if (dartResult[i] == 'T')
            c = pow(c, 3);
        //printf("%d ", i);
    }
    if (dartResult[s - 1] != '#' && dartResult[s - 1] != '*')
        v.push_back(c * d * m);
    int su = 0;
    for (i = 0; i < v.size(); ++i)
        su += v[i];
    return su;
}// * 3 T / # 9 D ~
int main()
{
    string s = "1T2D3D#";
    printf("%d", solution(s));
    return 0;
}
for (i = 0; i < v.size(); ++i)
    printf("%d ", v[i]);
printf("\n");
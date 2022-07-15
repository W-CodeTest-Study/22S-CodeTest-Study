#include <string>
#include <iostream>
#include <vector>
using namespace std;
bool solution(string s)
{
    vector<bool> v;
    int i;
    for (i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
            v.push_back(true); //벡터랑 스택이랑 비슷함
        else
        {
            if (v.empty()) //이미 비어있는데 닫으면 오류
                return 0;
            v.pop_back(); //닫는 괄호 나오면 팝
        }
    }
    if (v.empty()) //다 했을 때 v가 비어있어야 정상
        return 1;
    return 0;
}
#include <string>
#include <vector>
#include <math.h>
using namespace std;
pair<int, int> nown(int a)
{
    if (a == 1)    return { 1,4 };
    if (a == 2)    return { 2,4 };
    if (a == 3)    return { 3,4 };
    if (a == 4)    return { 1,3 };
    if (a == 5)    return { 2,3 };
    if (a == 6)    return { 3,3 };
    if (a == 7)    return { 1,2 };
    if (a == 8)    return { 2,2 };
    if (a == 9)    return { 3,2 };
    if (a == 0)    return { 2,1 };
}
int dis(pair<int, int> a, pair<int, int> b) //거리 구하기
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int i;
    pair<int, int> L = { 1,1 }, R = { 3,1 }, n;
    for (i = 0; i < numbers.size(); ++i)
    {
        n = nown(numbers[i]);
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) //예외
        {
            answer += 'L';
            L = n;
            continue;
        }
        if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) //예외
        {
            answer += 'R';
            R = n;
            continue;
        }
        if (dis(n, L) > dis(n, R)) //2,5,8,0일 때 더 가까운 거리 구하기
        {
            answer += 'R';
            R = n;
        }
        else if (dis(n, L) < dis(n, R))
        {
            answer += 'L';
            L = n;
        }
        else //거리가 같으면 자기 메인 손으로 누르기
        {
            if (hand[0] == 'r')
            {
                answer += 'R';
                R = n;
            }
            else
            {
                answer += 'L';
                L = n;
            }
        }
    }
    return answer;
}
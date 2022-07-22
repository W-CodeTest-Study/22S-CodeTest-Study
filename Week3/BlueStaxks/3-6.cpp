//#include <vector>
//#include <math.h>
//using namespace std;
//long long m[100000] = {};
//long long solution(int n, vector<int> times) //이분탐색 안쓴 방법
//{
//    long long i, min, mini, max = 0, c = 0, d;
//    double k = 0;
//    for (i = 0; i < times.size(); ++i)
//        k += 1.0 / (double)times[i]; //k는 가중치 총합
//    
//    for (i = 0; i < times.size(); ++i)
//    {
//        d = floor((double)n * (1.0 / (double)times[i]) / k);
//        c += d;
//        m[i] += d * times[i];
//    }
//    n -= c;
//
//    while (n)
//    {
//        for (i = 0; i < times.size(); ++i)
//        {
//            if (!i)
//            {
//                min = m[0] + times[0];
//                mini = 0;
//            }
//            else if (m[i] + times[i] < min)
//            {
//                min = m[i] + times[i];
//                mini = i;
//            }
//        }
//        m[mini] += times[mini];
//        n--;
//    }
//    for (i = 0; i < times.size(); ++i)
//        if (max < m[i])
//            max = m[i];
//    return max;
//}

//#include <vector>
//#include <algorithm>
//using namespace std;
//long long solution(int n, vector<int> times) //이분탐색 스케일을 시간 스케일로 풀기
//{
//    sort(times.begin(), times.end());
//    long long st = 1, en = (long long)times.back() * (long long)n, mid, i, c;
//    while (st <= en)
//    {
//        mid = (st + en) / 2;
//        for (i = 0, c = 0; i < times.size(); ++i)
//            c += mid / times[i];
//        if (c < n)
//            st = mid + 1;
//        else
//            en = mid - 1;
//    }
//    return st; //이렇게 이분탐색 하면 c==n인 경우가 여러개일 경우 그중 가장 작은 mid를 구할 수 있다.
//}

#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
long long solution(int n, vector<int> times) //첫 방법과 둘 째 방법을 합친 방법
{
    long long i, st, en, mi, c;
    double k = 0;
    for (i = 0; i < times.size(); ++i)
        k += 1.0 / (double)times[i]; //k는 가중치 총합
    en = 2 * floor((double)n / k);
    st = floor((double)n / k) / 2; //st와 en을 이렇게 어느정도 계산한 뒤 시작하면 더 빠름
    while (st <= en)
    {
        mi = (st + en) / 2;
        for (i = 0, c = 0; i < times.size(); ++i)
            c += mi / times[i];
        if (c < n)
            st = mi + 1;
        else
            en = mi - 1;
    }
    return st; //이렇게 이분탐색 하면 c==n인 경우가 여러개일 경우 그중 가장 작은 mid를 구할 수 있다.
}




#include <iostream>
int main()
{
    vector<int> t;
    t.push_back(7);
    t.push_back(10);
    cout<<solution(6, t);
    return 0;
}
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a >= b;
}
int solution(int n, vector<int> weak, vector<int> dist) //시계방향, 시계 반대방향,  뭐 다 의미없음
{
    int i, j, l, p, c, zp, k;
    vector<int> tc;
    sort(dist.begin(), dist.end(), cmp); //내림차순 정렬
    for (i = 1; i <= dist.size(); ++i)
    {
        for (j = 0; j < i; ++j)
            tc.push_back(dist[j]); //i는 tc의 개수를 정함 //긴 놈부터 들어감
        do {
            for (j = 0; j < weak.size(); ++j) //j는 weak를 shift하는 대용이라 보면 됨
            {
                zp = weak[j]; //제로 포인트를 맞춰 주는 것. 원형 데이터를 쓸 때 많이 쓰는 방법인데 첫 데이터를 0으로 맞춰버리는 것임 -> 나머지는 zp를 뺀 값으로 하고 그게 음수일 수도 있으므로 +n하고 %n을 함
                p = k = 0;
                for (l = 0; l < tc.size(); ++l)
                {
                    c = 0;
                    p += tc[l]; //p는 계속 제로 스케일에서 움직임
                    while ((weak[(k + j) % weak.size()] - zp + n) % n <= p) //커진 p이하의 weak포인트는 k로 다 쩨껴버림
                    {
                        k++;
                        c = 1;
                        if (k == weak.size())
                            return l + 1; //사실 이건 tc.size()와 같게 됨. 근데
                    }
                    if (!c) k++; //while문을 들어가 보지도 못하면 k가 안변하므로 따로 k++
                    p = (weak[(k + j) % weak.size()] - zp + n) % n; //k가 2까지 됐다면 p는 k가 3인 부분으로 맞춰야 됨 //제로 스케일을 맞추기 위해 -zp, +n, %n이 붙음 //k+j에서도 마찬가지로 %로 값을 맞춰줌
                }
            }
        } while (prev_permutation(tc.begin(), tc.end())); //tc의 순열을 만들어냄 //tc가 최대값으로 시작하므로 prev //이래야 4 2 3 만큼 써야될 때를 체크 가능
        tc.clear(); //tc 초기화
    }
    return -1; //아예 되는 경우가 없으면 여기로 나올거기 때문에 -1로 마무리
}


int main()
{
    vector<int> a(6);
    a[0] = 0; a[1] = 10; a[2] = 50; a[3] = 80; a[4] = 120; a[5] = 160;
    vector<int> b(5);
    b[0] = 1; b[1] = 10; b[2] = 5; b[3] = 40; b[4] = 30;

    cout << "\n\n" << solution(200, a, b);
    return 0;
}
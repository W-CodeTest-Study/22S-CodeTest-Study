#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit) //문제의 한정된 채점 데이터에 의해 정답이지만 엄밀하지 않은 풀이
{
    sort(people.begin(), people.end());
    int i, j, r = 0;
    for (i = people.size() - 1, j = 0; i >= j; i--, r++) //i는 무거운쪽, j는 가벼운쪽 시작
        if (people[i] + people[j] <= limit)
            j++; //큰거 넣는데 작은거 껴들어 갈 수 있으면 끼워 넣는 방식
    return r;
}

//#include <vector>
//#include <algorithm>
//using namespace std;
//int solution(vector<int> people, int limit)  //20 50 50 70 80 
//{
//	sort(people.begin(), people.end());
//	vector<bool> v(people.size(), false); //이미 태워 보냈으면 true 아니면 false
//	int i, j, c, d = 0, st, mi, en;
//	for (i = 0; i < people.size(); ++i, ++d)
//	{
//		if (v[i])	continue;
//		c = people[i];
//		v[i] = true;
//		st = i + 1;
//		en = people.size() - 1;
//		while (st <= en) //이분탐색을 곁들인
//		{
//			mi = (st + en) / 2;
//			if (people[mi] + c <= limit) //합쳐서 limit을 넘지 않는 최대값 구하기
//				st = mi + 1;
//			else
//				en = mi - 1;
//		}
//		for (j = en; j > i; --j) //0~i까지는 이미 다 보트 탐
//		{
//			if (j >= people.size() || v[j] || c + people[j] > limit)	continue;
//			v[j] = true;
//			break;
//		}
//	}
//	return d;
//}


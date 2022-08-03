#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int solution(int distance, vector<int> rocks, int n)
{
	if (rocks.size() == n)	return distance;
	sort(rocks.begin(), rocks.end());
	int i, t, st = 0, en = distance, mi, delete_count;
	while (st <= en) // 0 1 2 3 
	{				 // one 스케일이지만 0이 있음
		delete_count = 0;
		vector<bool> check(rocks.size(), false);
		mi = (st + en) / 2; //mi길이만큼은 건너야 됨 //mi 최대한 크게
		t = 0; //범위
		for (i = 0; i < rocks.size(); ++i)
		{
			while (t < rocks[i] && rocks[i] < t + mi) //이래야 건너 뛸 애들 건너뜀
			{
				check[i] = true; //지워야 하는 애들 true
				delete_count++;
				i++;
				if (i == rocks.size())	break;
			}
			if (i < rocks.size())	t = rocks[i];
		}
		i = rocks.size() - 1;
		while (rocks[i] > distance - mi) // distance % mi가 항상 0이 되는 것이 아니므로, 거리상으로는 괜찮지만 도착지점과의 거리에서 안될 수도 있어서 체크
		{
			if (!check[i])	delete_count++; //지워야 되는데 안지워진 애들 지우기 (실제로 check를 true로 바꿀 필요는 없음. 그냥 delete_count만 올리면 됨)
			i--;
		}
		if (delete_count > n)
			en = mi - 1;
		else if (delete_count <= n)
			st = mi + 1;
	}
	return en; //이런 식으로 이분탐색하면 같은 delete_count일 때 더 큰 mi를 구할 수 있음
}




#include <iostream>
int main()
{
	vector<int> v(3);
	v[0] = 4; v[1] = 8; v[2] = 11; //그냥 거리 가까운거를 막 지우면 이 경우 5라는 오답이 나옴
	cout<<solution(16, v, 2); //8
	return 0;
}


/*

	돌의 총 수만큼 지워야 한다면 바로 distance 리턴
	
	rocks를 오름차순으로 정렬

	start = 0, end = distance

	while(start <= end)
		돌 지운 횟수 = 0
		mid = (start + end) / 2

		돌 지운 횟수 = 돌 사이 간격이 최소 mid가 되게 하기 위해 지워야 하는 돌 개수

		if(돌 지운 횟수 > n)
			end = mid - 1
		else
			start = mid + 1

	end 리턴 //이렇게 이분탐색하면 같은 '돌 지운 횟수'일 때 가장 큰 mid값은 end값이 됨 


*/
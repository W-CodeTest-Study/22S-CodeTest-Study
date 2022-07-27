#include <iostream> //queue를 안쓰는 방법 //programmers 채점 기준으로 두 방법 모두 0.02ms 정도 나오지만 뒷 방법이 결국 더 빠를 것임
#include <stdlib.h> //이 방법은 while문을 너무 자주씀
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, int> um;
vector<int> solution(vector<string> operations)
{
	vector<int> v;
	vector<int> ni;
	int i, t, array_length = 0, index, maxi, mini, max, min;
	for (i = 0; i < operations.size(); ++i)
		if (operations[i][0] == 'I')
			v.push_back(stoi(operations[i].substr(operations[i].find(" ") + 1)));
	sort(v.begin(), v.end()); //중간에 껴넣는게 안되는거니까 껴넣을 필요 없게 미리 필드 생성
	for (i = 0; i < v.size(); ++i)
		um[v[i]] = i; //back 스케일
	vector<bool> va(operations.size(), false);
	for (i = 0; i < operations.size(); ++i)
	{
		if (operations[i][0] == 'I')
		{
			t = stoi(operations[i].substr(operations[i].find(" ") + 1));
			index = um[t];
			if (index && v[index - 1] == t) //여기서 안걸리면 더이상 쓸 일 없는 index라는 뜻
				um[t]--; //중복 처리
			va[index] = true;
			if (!array_length)
			{
				maxi = index;
				mini = index; //둘 다 back 스케일
			}
			else
			{
				if (index > maxi)	maxi = index;
				if (index < mini)	mini = index;
			}
			array_length++;
		}
		else if(array_length)
		{
		    if (operations[i][2] == '1')
		    {
				va[maxi] = false;
				if (array_length > 1)
					while (maxi && !va[--maxi]);
		    }
		    else
		    {
				va[mini] = false;
				if (array_length > 1)
				{
					while (mini < va.size() - 1 && !va[++mini]);
					t = va[mini];
					while (mini < va.size() - 1 && va[mini + 1] && v[mini + 1] == t)
						mini++; //back 스케일 맞추기
				}
		    }
			array_length--;
		}
	}
	vector<int> r;
	if (array_length)
	{
		r.push_back(v[maxi]);
		r.push_back(v[mini]);
		return r;
	}
	else
	{
		r.push_back(0);
		r.push_back(0);
		return r;
	}
}


//#include <iostream> //정석 풀이
//#include <stdlib.h>
//#include <vector>
//#include <queue>
//#include <string>
//#include <algorithm>
//using namespace std;
//priority_queue<pair<int, int>> max_heap;
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
//bool valid[1000000] = {}; //valid 배열로 두 queue를 싱크맞춤 //max_heap이나 min_heap에 있는 값은 위치는 달라도 같은 .second를 보유함
//void sync_max_heap()
//{
//    while (!max_heap.empty() && !valid[max_heap.top().second])
//        max_heap.pop();
//}
//void sync_min_heap()
//{
//    while (!min_heap.empty() && !valid[min_heap.top().second])
//        min_heap.pop();
//}
//vector<int> solution(vector<string> operations)
//{
//    int i, num;
//    for (i = 0; i < operations.size(); ++i)
//    {
//        if (operations[i][0] == 'I')
//        {
//            num = stoi(operations[i].substr(operations[i].find(" ") + 1));
//            min_heap.push({ num, i });
//            max_heap.push({ num, i });
//            valid[i] = true;
//        }
//        else
//        {
//            if (operations[i][2] == '1')
//            {
//                sync_max_heap();
//                if (!max_heap.empty())
//                {
//                    valid[max_heap.top().second] = false; //false로 바꾸기 전에 sync를 하기 때문에 true다음에 false가 나올 수 밖에 없고 둘이 섞이지 않음
//                    max_heap.pop();
//                }
//            }
//            else
//            {
//                sync_min_heap();
//                if (!min_heap.empty())
//                {
//                    valid[min_heap.top().second] = false;
//                    min_heap.pop();
//                }
//            }
//        }
//    }
//    sync_min_heap();
//    sync_max_heap();
//    vector<int> r;
//    if (max_heap.empty())
//    {
//        r.push_back(0);
//        r.push_back(0);
//        return r;
//    }
//    else
//    {
//        r.push_back(max_heap.top().first);
//        r.push_back(min_heap.top().first);
//        return r;
//    }
//}


#include <iostream>
int main()
{
    vector<string> v; //["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
    v.push_back("I -45");
    v.push_back("I 653");
    v.push_back("D 1");
    v.push_back("I -642");
    v.push_back("I 45");
    v.push_back("I 97");
    v.push_back("D 1");
    v.push_back("D -1");
    v.push_back("I 333");
    vector<int> r = solution(v);
    cout << r[0] << ' ' << r[1]; //333 -45
    return 0;
}
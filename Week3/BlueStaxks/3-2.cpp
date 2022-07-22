#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int people, i, start, end, query, t1, t2, answer = 0, t;
	vector<int> v[100];
	scanf("%d\n%d %d\n%d", &people, &start, &end, &query);
	for (i = 0; i < query; ++i)
	{
		scanf("%d %d", &t1, &t2);
		v[t1 - 1].push_back(t2 - 1); //양방향 그래프
		v[t2 - 1].push_back(t1 - 1);
	}
	queue<int> q;
	q.push(start - 1);
	bool hb[100] = {};
	hb[start - 1] = 1;
	while (!q.empty())
	{
		int s = q.size();
		while (s--)
		{
			t = q.front();
			if (t == end - 1)
			{
				printf("%d", answer);
				return 0;
			}
			q.pop();
			for (i = 0; i < v[t].size(); ++i)
			{
				if (!hb[v[t][i]])
				{
					q.push(v[t][i]);
					hb[v[t][i]] = 1;
				}
			}
		}
		answer++;
	}
	printf("-1"); //촌수 연결 안되면 -1
	return 0;
}
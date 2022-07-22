#include <iostream>
#include <queue>
#include <cstring>
#include <string>
bool hb[10000];
using namespace std;
void check()
{
	int a, b, t; //a에서 b로 가는 것 //t에 각 계산 결과 저장
	queue<pair<int, string>> q;
	memset(hb, false, sizeof(hb)); //배열을 계속 재선언 하는 것 보다 memset이 훨씬 빠름
	cin >> a >> b;
	q.push(make_pair(a, ""));
	hb[a] = 1;
	while (!q.empty())
	{
		int n = q.front().first;
		string s = q.front().second;
		q.pop();
		if (n == b)
		{
			cout << s << "\n";
			return;
		}
		t = n * 2;
		if (t >= 10000)	t %= 10000;
		if (!hb[t])
		{
			q.push(make_pair(t, s + "D"));
			hb[t] = 1;
		}
		t = n - 1;
		if (t < 0)	t = 9999;
		if (!hb[t])
		{
			q.push(make_pair(t, s + "S"));
			hb[t] = 1;
		}
		t = (n % 1000) * 10 + n / 1000;
		if (!hb[t])
		{
			q.push(make_pair(t, s + "L"));
			hb[t] = 1;
		}
		t = n / 10 + (n % 10) * 1000;
		if (!hb[t])
		{
			q.push(make_pair(t, s + "R"));
			hb[t] = 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n--)	check();
	return 0;
}
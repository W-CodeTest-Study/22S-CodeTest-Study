#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(string a, string b)
{
	if (a.length() == b.length()) //길이가 같으면 사전순으로 정렬
		return a < b;
	return a.length() < b.length(); //길이가 다르면 긴 순서대로 정렬
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); // 빠른 입출력을 위한 코드 3줄
	int n, i;
	cin >> n;
	string t;
	vector<string> v;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		v.push_back(t);
	} //여기까지 그냥 입력
	sort(v.begin(), v.end(), comp); //정렬함수
	v.erase(unique(v.begin(), v.end()), v.end()); //중복 제거 함수
	for (i = 0; i < v.size(); ++i)
		cout << v[i] << '\n';
	return 0;
}
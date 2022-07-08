#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(string &a, string &b)
{
	//printf("*");
	int i = 0, j = 0, t1 = 0, t2 = 0;
	char t;
	string s1 = "", s2 = "";
	while (!('0' <= a[i] && a[i] <= '9')) //헤드 파트
	{
		t = a[i];
		if ('A' <= t && t <= 'Z')
			t += 32;
		s1 += t;
		i++;
	}
	while (!('0' <= b[j] && b[j] <= '9'))
	{
		t = b[j];
		if ('A' <= t && t <= 'Z')
			t += 32;
		s2 += t;
		j++;
	}
	if (s1 != s2)
		return s1 < s2;
	while (('0' <= a[i] && a[i] <= '9')) //숫자 파트
	{
		t1 *= 10;
		t1 += a[i] - '0';
		i++;
	}
	while (('0' <= b[j] && b[j] <= '9'))
	{
		t2 *= 10;
		t2 += b[j] - '0';
		j++;
	}
	return t1 <= t2;
}
vector<string> solution(vector<string> files)
{
	string t;
	for (int i = 0; i < files.size(); ++i) //버블 정렬
		for (int j = 0; j < files.size() - 1 - i; ++j)
			if (!comp(files[j], files[j + 1]))
			{
				t = files[j];
				files[j] = files[j + 1];
				files[j + 1] = t;
			}
	//sort(files.begin(), files.end(), comp);
	return files;
}
#include <iostream>
#include <string>
using namespace std;
int towh1[600005]; //여기서 0이 나오면 안됨
int towh2[600005]; //one 스케일 //서로 역함수 느낌
string s;
int c, sl; //제로 스케일 --> c 자체가 s의 몇 번쨰 (1부터)
void init()
{
	sl = s.length();
	for (int i = 0; i < sl; ++i)
	{
		towh1[i] = i + 1; //towh[1]=2 --> 1번째 글자 뒤에 2번째 글자 //[]안의 수 번째보다 한 칸 뒤 위치를 나타냄
		towh2[i + 1] = i; //towh[2]=1 --> 2번째 글자 앞엔 1번째 글자 //[]안의 수 번째보다 한 칸 앞 위치를 나타냄
	}
	towh2[0] = 0;
}
void doB()
{
	if (!towh1[c]) //c가 가장 마지막이면
	{
		int t = towh2[c];
		towh1[t] = 0;
		towh2[c] = 0;
		sl--;
		c = t;
		return;
	}
	int t = towh1[c];
	towh1[towh2[c]] = t;
	towh2[t] = towh2[c]; //이러면 두 배열에서 c라는 값이 사라지면서 비게됨
	sl--;
	c = towh2[c];
}
void doP()
{
	char tc;
	cin >> tc;
	s += tc;
	if (!towh1[c]) //맨 뒤에 넣는 경우
	{
		towh1[c] = s.length();
		towh2[s.length()] = c;
		sl++;
		c = towh1[c];
		return;
	}
	int t = towh1[c];
	towh1[c] = s.length();
	towh1[s.length()] = t;
	towh2[t] = s.length();
	towh2[s.length()] = c;
	sl++;
	c = towh1[c];
}
void print(int a, int l) //재귀를 쓰기 때문에 따로 함수 사용
{
	if (l == sl)	return;
	cout << s[a - 1];
	print(towh1[a], l + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); //빠른 입출력
	int a, i;
	char t;
	cin >> s;
	init(); //towh 배열 설정
	c = sl;
	cin >> a;
	for (i = 0; i < a; ++i)
	{
		cin >> t;
		if (t == 'L')
			c = towh2[c]; //안전
		if (t == 'D' && towh1[c]) //안전 장치
			c = towh1[c];
		if (t == 'B' && c)
			doB();
		if (t == 'P')
			doP();
		/*printf("-->");
		print(towh1[0], 0);
		printf("\n          0 1 2 3 4 5 6 7 9\ntowh1 --> ");
		for (int j = 0; j < 10; ++j)
			printf("%d ", towh1[j]);
		printf("\ntowh2 --> ");
		for (int j = 0; j < 10; ++j)
			printf("%d ", towh2[j]);
		printf("\nfull --> ");
		cout << s << "\n\n";*/ //중간 과정 확인
	}
	print(towh1[0], 0);//출력은 제로 스케일로
	return 0;
}
// a b c d
//0 1 2 3 4    <-- c
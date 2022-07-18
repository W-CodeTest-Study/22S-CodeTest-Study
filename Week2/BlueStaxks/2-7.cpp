#include <iostream>
#include <string>
using namespace std;
int to_next[600005]; //여기서 0이 나오면 안됨
int to_front[600005]; //one 스케일 //서로 역함수 느낌
string s; //계속 사용할 문자열
int cursor, synthetic_length; //제로 스케일 --> cursor 자체가 s의 몇 번쨰 (1부터)
void init()
{
	synthetic_length = s.length(); //synthetic_length는 s의 실제 길이 말고 편집에 의한 길이임. B를 한다고 해서 실제 s가 지워지진 않지만 synthetic_length는 1 작아짐
	for (int i = 0; i < synthetic_length; ++i)
	{
		to_next[i] = i + 1; //to_next[1]=2 --> 1번째 글자 뒤에 2번째 글자 //[]안의 수 번째보다 한 칸 뒤 위치를 나타냄
		to_front[i + 1] = i; //to_front[2]=1 --> 2번째 글자 앞엔 1번째 글자 //[]안의 수 번째보다 한 칸 앞 위치를 나타냄
	}
	to_front[0] = 0; //연속된 L에 대응
}
void doB()
{
	if (!to_next[cursor]) //cursor가 가장 마지막이면
	{
		int t = to_front[cursor];
		to_next[t] = 0; //0으로 만들어야 D를 했을 때 정상적인 대응 가능
		to_front[cursor] = 0;
		synthetic_length--;
		cursor = t;
		return;
	}
	int t = to_next[cursor];
	to_next[to_front[cursor]] = t; //1번 글자가 2번, 2번 글자가 3번을 가리킬 때, 1번 글자가 바로 3번을 가리키도록 변경하는 것
	to_front[t] = to_front[cursor]; //이러면 두 배열에서 cursor라는 값이 사라지면서 비게됨
	synthetic_length--;
	cursor = to_front[cursor];
}
void doP()
{
	char additional_char;
	cin >> additional_char;
	s += additional_char;
	if (!to_next[cursor]) //맨 뒤에 넣는 경우
	{
		to_next[cursor] = s.length();
		to_front[s.length()] = cursor;
		synthetic_length++;
		cursor = to_next[cursor];
		return;
	}
	int t = to_next[cursor];
	to_next[cursor] = s.length(); //길이가 3, 커서가 2번째 글자 오른쪽에 있는 경우에 P를 하면 string s 바로 뒤에 새 문자가 추가됨
	to_next[s.length()] = t; //그리고 2번 글자가 3번을 가리켰지만 2번 글자가 마지막 4번 글자를 가리키게 하고 4번 글자는 3번 글자를 가리키도록 함
	to_front[t] = s.length(); //이러면 나중에 재귀를 통해 올바른 순서대로 모두 출력할 수 있고, 문자열을 중간에 변경할 필요가 없어져서 속도가 빠름
	to_front[s.length()] = cursor;
	synthetic_length++;
	cursor = to_next[cursor];
}
void print(int index, int printers_length) //재귀를 쓰기 때문에 따로 함수 사용
{
	if (printers_length == synthetic_length)	return; //printers_length가 제로 스케일이라 synthetic_length와 같아지면 그 전에 이미 끝난 
	cout << s[index - 1]; //빠른 입출력 코드를 쓰면 printf를 못씀
	print(to_next[index], printers_length + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); //빠른 입출력
	int task_count, i;
	char t;
	cin >> s;
	init();
	cursor = synthetic_length;
	cin >> task_count;
	for (i = 0; i < task_count; ++i)
	{
		cin >> t;
		if (t == 'L')
			cursor = to_front[cursor]; //안전
		if (t == 'D' && to_next[cursor]) //안전 장치
			cursor = to_next[cursor]; //한 칸 앞으로 커서가 이동
		if (t == 'B' && cursor)
			doB();
		if (t == 'P')
			doP();
		/*printf("-->");
		print(to_next[0], 0);
		printf("\n          0 1 2 3 4 5 6 7 9\nto_next  --> ");
		for (int j = 0; j < 10; ++j)
			printf("%d ", to_next[j]);
		printf("\nto_front --> ");
		for (int j = 0; j < 10; ++j)
			printf("%d ", to_front[j]);
		printf("\nfull --> ");
		cout << s << "\n\n";*/ //중간 과정 확인
	}
	print(to_next[0], 0);//출력은 제로 스케일로 // 첫 글자가 사라졌을 수도 있으므로 0부터 시작
	return 0;
}
// a b c d
//0 1 2 3 4    <-- cursor

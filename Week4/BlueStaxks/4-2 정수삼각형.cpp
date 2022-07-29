#include <vector>
#include <math.h>
using namespace std;
int m[500][500] = {};
int solution(vector<vector<int>> triangle) //아주 기본적인 DP문제
{
	if (triangle.size() == 1)	return triangle[0][0]; //높이가 1이면 뭐 할거 없이 리턴
	m[0][0] = triangle[0][0]; //초기값
	int i, j, ma = 0;
	for (i = 1; i < triangle.size(); ++i)
		for (j = 0; j < triangle[i].size(); ++j)
		{
			if (!j) //가장 왼쪽
				m[i][0] = m[i - 1][0] + triangle[i][0];
			else if(j == triangle[i].size() - 1) //가장 오른쪽
				m[i][j] = m[i - 1][j - 1] + triangle[i][j];
			else //중간
				m[i][j] = max(m[i - 1][j - 1], m[i - 1][j]) + triangle[i][j]; //위 2개중 더 큰거 선택
		}
	for (i = 0; i < triangle.back().size(); ++i)
		if (m[triangle.size() - 1][i] > ma)	ma = m[triangle.size() - 1][i];
	return ma;
}
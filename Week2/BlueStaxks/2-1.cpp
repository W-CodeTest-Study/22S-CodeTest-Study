#include <vector>
#include <iostream>
using namespace std;
vector<int> solution(vector<int> arr)
{
    vector<int> r;
    r.push_back(arr[0]);
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i - 1] != arr[i]) //다를 경우만 넣기
            r.push_back(arr[i]);
    return r;
}
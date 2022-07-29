#include <string>
#include <vector>
using namespace std;
string solution(string number, int k)
{
    int i, ptr = 0, tk = k, c = 0; //ptr은 one 스케일
    vector<int> to_front(number.length() + 1, 0);
    vector<int> to_back(number.length() + 1, 0); //이거 참 내가 만들었지만 참 좋은 방법이구먼
    for (i = 0; i < to_back.size() - 1; ++i)     //8ms도 안나오는 엄청난 속도!!
    {
        to_back[i] = i + 1; //여기서 0이 나오면 마지막이란 뜻
        to_front[i + 1] = i;
    }
    while (k)
    {
        while (1)
        {
            if (number[to_back[ptr] - 1] < number[to_back[to_back[ptr]] - 1])   // s  to_back[s]   to_back[to_back[s]]
            {                                                                   // 4       1                 7
                int t = to_back[to_back[ptr]];
                to_back[ptr] = t;
                to_front[t] = ptr;  //1 -> 2 -> 3   --->>   1 -> 3
                k--;
                break;
            }
            else
            {
                ptr = to_back[ptr];
                if (!ptr) //마지막 글자
                {
                    c = 1;
                    break;
                }
            }
        }
        if (c) //k가 남아있어도 나와야됨
            break;
        ptr = to_front[ptr];
    }
    string r = "";
    ptr = 0;
    for (i = 0; i < number.length() - tk; ++i) //여기까지 왔는데 k가 남아있다면 그냥 뒤를 자르면 됨
    {
        ptr = to_back[ptr];
        r += number[ptr - 1]; //one 스케일 보정
    }
    return r;
}




#include <iostream>
int main()
{
    string r = "4177252841"; //"775841"
    cout<<solution(r, 4);
    return 0;
}
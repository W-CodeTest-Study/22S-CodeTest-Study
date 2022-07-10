#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> um;
string exOG(string& a) //page의 오리지널 주소 반환
{
    int p1, p2;
    p1 = a.find("<meta property=\"og:url\" content=\"");
    p2 = a.find("\"/>\n", p1 + 33);
    return a.substr(p1 + 33, p2 - (p1 + 33));
}
void down(string& a) //소문자로 바꾸기
{
    int i;
    for (i = 0; i < a.length(); ++i)
        if ('A' <= a[i] && a[i] <= 'Z')
            a[i] += 32;
}
int solution(string word, vector<string> pages)
{
    int i, j, p, p1, p2, p3, c;
    int n[20] = {}; //기본 점수
    int ol[20] = {}; //외부 링크 개수
    double s[20] = {}; //최종 점수
    vector<string> pl;
    vector<int> v[20];
    down(word);
    for (i = 0; i < pages.size(); ++i)
    {
        pl.push_back(exOG(pages[i])); //pl의 인덱스가 주소 string을 가지고 있음
        um[pl.back()] = i; //um에 string(주소)를 넣으면 그 인덱스가 나옴
    }
    for (i = 0; i < pages.size(); ++i)
    {
        c = 0;
        p1 = pages[i].find("/>\n</head>  \n<body>\n");
        string t = pages[i].substr(p1 + 20, pages[i].length() - 16 - (p1 + 20)); //t는 내용
        down(t);
        t += '*'; //bad_excess를 막기 위해 문자 추가
        p1 = t.find(word);
        if (!p1 && !('a' <= t[p1 + word.length()] && t[p1 + word.length()] <= 'z')) //t의 시작부터 찾는 단어가 나올 수 있기에 따로 분류(아래에서 p1-1을 하는데 p1이 0이면 안됨)
            c++;
        p1 = t.find("<a href=\""); //t의 시작부터 외부 링크가 나올 수 있음
        if (!p1)
        {
            p1 = t.find("\">", 10);
            ol[i]++;
            if (um.count(t.substr(9, p1 - 9)))
                if (um[t.substr(9, p1 - 9)] != um[pl[i]])
                    v[um[t.substr(9, p1 - 9)]].push_back(um[pl[i]]);
        }
        for (j = 1; j < t.length() - 1; ++j) //t(body)에서 단어와 외부 링크를 동시에 검색
        {
            if (j <= t.length() - word.length())
            {
                p1 = t.substr(j, word.length()).find(word); //p1은 제로 스케일
                if (!p1) //찾는 단어가 j에 딱 있으면 걸림, 그때 p1은 0
                    if (!('a' <= t[j - 1] && t[j - 1] <= 'z') && !('a' <= t[j + word.length()] && t[j + word.length()] <= 'z')) //단어 앞 뒤로 알파벳이 있으면 안됨
                    {
                        c++;
                        j += word.length() - 1; //찾으면 j 점프
                    }
            }
            if (j <= t.length() - 9)
            {
                p1 = t.substr(j, 9).find("<a href=\"");
                if (!p1)
                {
                    p2 = t.find("\">", j + 10); //p2는 t 스케일
                    ol[i]++;
                    if (um.count(t.substr(j + 9, p2 - j - 9))) //unordered_map의 특성상 없는 key를 검색하면 0으로 나오기 때문에 v[0]이 되는 것을 막기 위해 먼저 key가 있는지 확인
                        if (um[t.substr(j + 9, p2 - j - 9)] != um[pl[i]])
                            v[um[t.substr(j + 9, p2 - j - 9)]].push_back(um[pl[i]]); //v[page에 써있는 외부 링크]에 지금 page의 주소를 추가 //이래야 나중에 검색이 쉬움
                    p3 = t.find("</a>", p2 + 2);
                    j = p3 + 2; //외부 링크 처리가 끝나면 j 점프
                }
            }
        }
        n[i] = c; //기본 점수
    }
    double td, ms = -1;  //여기부턴 점수 집계
    int ri;
    for (i = 0; i < pages.size(); ++i)
    {
        s[i] = (double)n[i]; //먼저 기본 점수로 맞춰두기
        td = 0;
        for (j = 0; j < v[i].size(); ++j) //v[i]에는 i로 가는 j들이 있음
            td += (double)n[v[i][j]] / (double)ol[v[i][j]];
        s[i] += td;
        if (s[i] > ms)
        {
            ms = s[i];
            ri = i;
        }
    }
    return ri;
}

int main()
{
    vector<string> v;
    v.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>");
    vector<string> t;
    t.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>");
    t.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>");
    t.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>");
    cout << solution("BLIND", t);
    return 0;
}
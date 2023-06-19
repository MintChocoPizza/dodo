#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int N;
int alphaMatchNum[26];      // 0->A ~ 25->Z
string str[10];
string tempStr = "";
bool visitedNum[10];

void input()
{
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> str[i];
        tempStr += str[i];
    }
}

int sumAlpha()
{
    int ret = 0;

    for(int i=0; i<N; ++i)
    {
        int temp = 0;
        for(int idx=0; idx<str[i].size(); ++idx)
        {
            char c = str[i][idx];
            temp *= 10;
            temp += alphaMatchNum[c-'A'];
        }
        ret += temp;
    }
    return ret;
}

int BF(int cnt)
{
    int ret = 0;
    int alpha = tempStr[cnt]-'A';
    // 기저 사례
    // 1. 모든 문자를 탐색하였다면 값을 반환한다.
    if(cnt == tempStr.size())
    {
        return sumAlpha();
    }
    // 2. 만약 방문한 적이 있는 alpha인경우 다음 문자를 탐색한다. 
    if(alphaMatchNum[alpha] != -1) 
    {
        return BF(cnt+1);
    }

    // 재귀호출
    for(int i=0; i<10; ++i)
    {
        if(visitedNum[i]) continue;
        visitedNum[i] = true;
        alphaMatchNum[alpha] = i;
        int cand = BF(cnt + 1);
        ret = max(ret, cand);
        
        alphaMatchNum[alpha] = -1;
        visitedNum[i] = false;
    }

    return ret;
}

int main()
{
    memset(alphaMatchNum, -1, sizeof(alphaMatchNum));
    memset(visitedNum, 0, sizeof(visitedNum));

    input();
    
    cout << BF(0);

    return 0;
}

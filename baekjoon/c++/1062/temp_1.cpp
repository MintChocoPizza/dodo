#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int N, K;
vector<string> v_S;
bool alpha[26];

bool input()
{
    cin >> N >> K;

    for(int i=0; i<N; ++i)
    {
        string temp;
        cin >> temp;
        v_S.push_back(temp);
    }

    if(K<5)     // antic는 무조건 들어가야함
    {
        return false;
    }

    return true;
}

int reading()
{
    int ret = 0;

    for(int i=0; i<N; ++i)
    {
        
    }

    return ret;
}

int maxReadChar(int idx, int cnt)
{
    // 기저 사례
    if(cnt == K)    // K개의 글자를 다 봅았다. 몇개의 글자를 읽을 수 있는지 확인한다. 
    {
        return reading();
    }

    int ret = 0;

    for(int i=idx; i<26; ++i)
    {
        if(alpha[i]) continue;
        alpha[i] = true;
        int cand = maxReadChar(idx+1, i+1);
        ret = max(ret, cand);
        alpha[i] = false;
    }

    return ret;
}

int main()
{
    if(!input())
    {
        cout << 0;
        return 0;
    }

    // 무조건 읽고 사용하는 글자 5개 
    alpha['a'-'a'] = true;
    alpha['n'-'a'] = true;
    alpha['t'-'a'] = true;
    alpha['i'-'a'] = true;
    alpha['c'-'a'] = true;
    K -= 5;

    cout << maxReadChar(0, 0);

    return 0;
}


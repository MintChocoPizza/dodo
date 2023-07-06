#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K;
vector<string> v_S;
int alpha[26];



void input()
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
        cout << 0 << '\n';
        exit(0);
    }
}

int reading()
{
    int ret = 0;

    for(int i=0; i<v_S.size(); ++i)
    {
        bool check = true;
        for(int j=0; j<v_S[i].length(); ++j)
        {
            if(!alpha[v_S[i][j] - 'a'])
            {
                check = false;
                break;
            }
        }

        if(check)
            ret++;
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

    for(int i=0; i<26; ++i)
    {
        if(alpha[i]) continue;

        alpha[i] = true;
        int cand = maxReadChar(i, cnt+1);
        ret = max(ret, cand);
        alpha[i] = false;
    }

    return ret;
}

int main()
{
    input();

    // 무조건 읽고 사용하는 글자 5개 
    alpha['a'-'a'] = true;
    alpha['n'-'a'] = true;
    alpha['t'-'a'] = true;
    alpha['i'-'a'] = true;
    alpha['c'-'a'] = true;
    K -= 5;

    cout << maxReadChar(0, 0);
}

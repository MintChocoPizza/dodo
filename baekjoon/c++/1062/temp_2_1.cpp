#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, K;
int words[51];
int check;

bool input()
{
    cin >> N >> K;
    string temp;
    for(int i=0; i<N; ++i)
    {
        cin >> temp;
        for(int j=0; j<temp.size(); ++j)
        {
            words[i] |= 1 << (temp[j] - 'a');
        }
    }

    if(K < 5)
    {
        //cout << 0;
        // exit(0);
        return false;
    }

    return true;
}

int maxWord()
{
    int ret = 0;

    for(int i=0; i<N; ++i)
    {
        if((words[i] & check) == words[i])
            ret++;
    }

    return ret;
}

int backtracking(int depth, int idx)
{
    if(depth == K)
    {
        return maxWord();
    }
    
    int ret = 0;
//    for(int i=idx; i<26; ++i)
//    {
//        if(check & (1<<i)) continue;
//        check |= (1<<i);
//        int cand = backtracking(depth+1, i+1);
//        ret = max(ret, cand);
//        check &= !(i << i);
//    }
    for(int i = idx; i < 26; i++)
    {
        if(check & (1<<i)) continue;
        check |= (1 << i);
        int cand = backtracking(depth + 1, i + 1);
        ret = max(ret, cand);
        check &= ~(1 << i);
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

    check |= 1 << ('a' - 'a');
    check |= 1 << ('c' - 'a');
    check |= 1 << ('i' - 'a');
    check |= 1 << ('t' - 'a');
    check |= 1 << ('n' - 'a');    

    K -= 5;

    cout << backtracking(0, 0);

    return 0;
}

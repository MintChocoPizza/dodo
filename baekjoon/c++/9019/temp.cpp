#include <iostream>
#include <iterator>
#include <string>
#include <queue>

#define MOD 10000

using namespace std;

struct DSLR
{
    string str;
    int num;
};

int numLen(int num)
{
    int digit = 0;

    while(num != 0)
    {
        num /= 10;
        ++digit;
    }

    return digit;
}

DSLR dslr(int version, DSLR cur)
{
    int len = numLen(cur.num);
    DSLR ret;
    ret.str = cur.str;
    
    queue<int> q;

    switch (version)
    {
        case 0:     // D
            ret.num = (cur.num * 2) % MOD;
            ret.str += "D";
            break;
        case 1:     // S
            if(cur.num == 0)
                ret.num = 9999;
            else 
                ret.num = cur.num-1;

            ret.str += "S";
            break;
        case 2:     // L
            int first;
            break;
        case 3:     // R
            break;
    }

    return ret;
}

string bfs(int starting, int ending)
{
    DSLR first;
    queue<DSLR> q;
    int min = 987654321;

    first.num = starting;
    first.str = "";

    q.push(first);

    while (!q.empty())
    {
        DSLR cur = q.front();
        q.pop();

        if(cur.num == ending)
        {
            return cur.str;
        }

        for(int i=0; i<4; ++i)
        {
            q.push(dslr(i, cur));
        }
    }
    
    return "-1";
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int A, B;
        cin >> A >> B;

        string s = "";

        s += "1234";
        cout << s;
        
    }
}

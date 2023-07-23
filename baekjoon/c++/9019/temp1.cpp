#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int chg_int(string s)
{
    int ret = 0;

    for(int i=0; i<s.length(); ++i)
    {
        ret = (ret*10)+(s[i]-'0');
    }

    return ret;
}

string chg_string(int num)
{
    string ret = "";
    vector<int> v;

    
    if(num == 0)
        return "0";

    while(num != 0)
    {
        v.push_back(num%10);
        num /= 10;
    }

    while(!v.empty())
    {
        ret += (v.back() + '0');
        v.pop_back();
    }
    
    return ret;
}

pair<string, string> dslr(string s, string ret, int opt)
{
    int num = chg_int(s);
    string s_s = "";
    string s_ret = ret;

    switch (opt)
    {
        case 0:         // D
            num = (num << 1) % 10000;
            s_s = chg_string(num);
            s_ret += "D";
            break;
        case 1:         // S
            if(num == 0)
                num = 9999;
            else 
                num -= 1;
            s_s = chg_string(num);
            s_ret += "S";
            break;
        case 2:          // L
        {
            char temp = s[0];
            for(int i=1; i<s.length(); ++i)
            {
                s_s += s[i];
            }
            s_s += temp;
            s_ret += "L";
            break;
        }
        case 3:         // R
        {
            char temp = s[s.length()-1];
            for(int i=0; i<s.length()-1; ++i)
            {
                s_s += s[i];
            }
            s_s += temp;
            s_ret += "R";
        }
            break;
    }

    return make_pair(s_s, s_ret);
}

string bfs(string A, string B)
{
    string ret = "";
    queue<pair<string, string> > q;
    q.push(make_pair(A, ""));

    while(!q.empty())
    {
        string s = q.front().first;
        ret = q.front().second;
        q.pop();

        if(s == B)
        {
            return ret;
        }

        for(int i=0; i<4; ++i)
        {
            q.push(dslr(s, ret, i));
        }
    }

    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string A, B;
        cin >> A >> B;

        cout << bfs(A, B) << '\n';
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <string>

#define MOD 10000

using namespace std;

int visited[10000];

pair<int, string> dslr(int num, string str, int opt)
{
    int numRet = 0;
    string strRet = str;

    switch(opt)
    {
        case 0:     // D
            numRet = (num << 1)%MOD;
            strRet += "D";
            break; 
        case 1:     // S
            if(num == 0) 
                numRet = 9999;
            else 
                numRet = num-1;
            strRet += "S";
            break;
        case 2:     // L
            {
                int numLen = 1;
                int i;
                for(i=10; i<10000; i *=10)
                {
                    if(i<=num)
                        ++numLen;
                }
                i /=10;

                int temp = num/i;
                numRet = (num-(temp*i))*10 + temp;
                strRet += "L";
            }
            break;
        case 3:     // R
            {
                int temp = num%10;
                numRet = num/10;
                if(temp)
                {
                    while(temp<numRet)
                        temp*=10;
                }
                numRet += temp;

                strRet += "R";
                
            }
            break;
    }

    return make_pair(numRet, strRet);
}

string bfs(int A, int B)
{
    string ret = "";

    queue<pair<int, string> > q;
    q.push(make_pair(A, ""));

    while(!q.empty())
    {
        int num = q.front().first;
        string ret = q.front().second;
        q.pop();

        if(num == B) 
        {
            return ret;
        }
        if(visited[num] != -1) continue;
        visited[num] = true;

        for(int i=0; i<4; ++i)
        {
            q.push(dslr(num, ret, i));
        }
    }

    return "No search" ;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int A, B;
        cin >> A >> B;

        memset(visited, -1, sizeof(visited));

        cout << bfs(A, B) << '\n';
    }

    return 0;
}

#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int visited[10000];

string bfs(int A, int B)
{
    queue<pair<int, string> > q;
    q.push(make_pair(A, ""));
    visited[A] = true;

    while(!q.empty())
    {
        int num = q.front().first;
        string str = q.front().second;
        q.pop();

        if(num == B)
        {
            return str;
        }

        int temp;

        temp = (num << 1) % 10000;
        if(visited[temp] == -1)
        {
            visited[temp] = true;
            q.push(make_pair(temp, str+"D"));
        }

        temp = num-1<0 ? 9999 : num-1;
        if(visited[temp] == -1)
        {
            visited[temp] = true;
            q.push(make_pair(temp, str+"S"));
        }
        
        temp = (num%1000)*10 + (num/1000);
        if(visited[temp] == -1)
        {
            visited[temp] = true;
            q.push(make_pair(temp, str+"L"));
        }

        temp = (num/10) + (num%10)*1000;
        if(visited[temp] == -1)
        {
            visited[temp] = true;
            q.push(make_pair(temp, str+"R"));
        }
        
    }

    return "error \n";
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
}

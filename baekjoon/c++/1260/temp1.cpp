#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001];
int N, M, V;
int visited[1001];

void DFS(int v)
{
    // 정점에 방문했을 때 한번 출력한다. 
    cout << v << ' ';
    
    // 현재 정점을 방문표시 한다. 
    visited[v] = true;
    for(int i=1; i<=N; ++i)
    {
        // 만약 간선연결이 안되어있건, 방문한 적 있다면 넘어감
        if(arr[v][i]==false || visited[i]) continue;

        DFS(i);
    }
}

void BFS(int v) 
{
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()) 
    {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';
        cout << endl;
        for(int i=1; i<=N; ++i)
        {
            // 간선으로 연결되어 있고, 방문한 적이 없다면
            if(arr[v][i]==true && visited[i]==false)
            {
                visited[i] = true;
                q.push(i);
                cout << i << ' ';
            }
        }
        cout << endl;
        
    }

    
}

int main() 
{
    cin >> N >> M >> V;

    for(int i=0; i<M; ++i)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }

    DFS(V);
    cout << endl;
    memset(visited, false, sizeof(visited));
    BFS(V);

    for(int i=1; i<=N; ++i)
    {
        cout << visited[i] << ' ';
    }
    cout << endl;
    for(int i=1; i<=N; ++i) 
    {
        for(int j=i+1; j<=N; ++j)
        {
            cout << i << ' ' << j << ' ' <<arr[i][j] << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <math.h>

using namespace std;

int N;
int arr[21][21];
int Min = 1000000000;
bool visited[22];

void BT(int cnt, int idx)
{
    if(cnt == N/2)
    {
        int start;
        int link;
        start=0;
        link=0;

        for(int x=1; x<=N; x++)
        {
            for(int y=1; y<=N; y++)
            {
                if(visited[x] == true && visited[y] == true) start += arr[x][y];
                if(visited[x] == false && visited[y] == false) link += arr[x][y];
            }
        }

        int temp = abs(start - link);
        if(Min > temp) Min = temp;
        return;
    }

    // i<=N, = 하나 차이로 수행 시간이 2배 차이
    for(int i=idx; i<N; i++)
    {
        visited[i] = true;
        BT(cnt+1, i+1);
        visited[i] = false;
    }
}

int main()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
        }
    }

    BT(0,1);

    cout << Min;
}

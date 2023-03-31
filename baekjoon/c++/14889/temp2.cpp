#include <cstdint>
#include <iostream>

using namespace std;

int N;
int arr[20][20];
bool visited[20];
int Min = INT32_MAX;

void BT(int cnt)
{
    int i, j;

    if(cnt == N/2)
    {
        int start=0, link=0;
        int i, j;
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                if(visited[i] && visited[j]) start += arr[i][j];
                if(!visited[i] && !visited[j]) link += arr[i][j];
            }
        }
        
        int temp = abs(start - link);

        if(Min > temp) Min = temp;

        return;
    }
    for(i=0; i<N; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        BT(cnt+1);
        visited[i] = false;
    }
}

int main()
{
    int i, j;

    cin >> N;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }

    BT(0);

    cout << Min;

    return 0;
}

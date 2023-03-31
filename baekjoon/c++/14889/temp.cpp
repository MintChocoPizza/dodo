#include <iostream>
#include <math.h>

using namespace std;

int N;
int arr[20][20];
int visited[20];
int Min = INT32_MAX;

void BT(int cnt, int num)
{
    int i, j;
    
    if(cnt == N/2)
    {
        int start=0, link=0;
        for(i=0; i<N; i++)
        {
            for(j=i+1; j<N; j++)
            {
                if(visited[i] && visited[j])
                    start += arr[i][j] + arr[j][i];
                if(!visited[i] && !visited[j])
                    link += arr[i][j] + arr[j][i];
            }
        }

        int temp = abs(start-link);
        if(Min>temp)
            Min = temp;
        return;
    }

    for(i=num; i<N; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        BT(cnt+1, num+1);
        visited[i] = false;
    }
}

int main()
{
    // 예제 입력
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    BT(0,0);

    cout << Min;

    return 0;
}

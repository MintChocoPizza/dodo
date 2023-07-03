#include <iostream>
#include <algorithm>

using namespace std;

int N;
int W[1000];
int visited[1000];  // x번째 에너지 구슬을 제거한다. 

void input()
{
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> W[i];
    }
}

int sumEnergy(int idx)
{
    int right;
    int left;

    for(int i=idx; i<N; ++i)
    {
        if(!visited[i])
        {
            right = W[i];
            break;
        }
    }

    for(int i=idx; i>=0; --i)
    {
        if(!visited[i])
        {
            left = W[i];
            break;
        }
    }

    return right*left;
}

int energyMax(int cnt, int sum)
{
    // 기저사례 
    if(cnt == 2)
    {
        return sum;
    }

    int ret = 0;

    for(int i=1; i<N-1; ++i)
    {
        if(visited[i]) continue;
        visited[i] = true;

        int temp = sumEnergy(i);
        int cand = energyMax(cnt-1, sum+temp);
        
        ret = max(ret, cand);

        visited[i] = false;
    }

    return ret;
}

int main()
{
    input();

    cout << energyMax(N, 0);

    return 0;
}

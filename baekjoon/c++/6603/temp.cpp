#include <iostream>

using namespace std;

int k;
int arrNum[13];
bool visited[13];


void BF(int cnt, int idx)
{
    // 기저사례
    // 6개의 숫자를 다 뽑았다면
    if(cnt == 6)
    {
        // 출력 
        for(int i=0; i<k; ++i)
        {
            if(visited[i])
            {
                cout << arrNum[i] << ' ';
            }
        }
        cout << '\n';
        return ;
    }

    for(int i=idx; i<k; ++i)
    {
        if(visited[i]) continue;
        visited[i] = true;

        BF(cnt + 1, i+1);

        visited[i] = false;
    }

}

int main()
{
    while(1)
    {
        cin >> k;
        if(k == 0)
            break;

        for(int i=0; i<k; ++i)
        {
            cin >> arrNum[i];
        }

        BF(0, 0);
        cout << '\n';
    }
    
    return 0;
}

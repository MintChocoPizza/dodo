#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for(int i=2; i*i<=N;)
    {
        if(N%i == 0)
        {
            cout << i << '\n';
            N /= i;
        }
        else
        {
            i++;
        }
    }
    
    if(N != 1)
    {
        cout << N << '\n';
    }

    return 0;
}
// 이 코드가 수행시간이 더 짧음

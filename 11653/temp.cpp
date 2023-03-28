#include <iostream>
#include <cmath>

using namespace std;

int arr[10000001] = {0,1,0,};

int main()
{
    int N;
    cin >> N;

    for(int i=2; i<=sqrt(N); i++)
    {
        if(!arr[i])
        {
            for(int j=i*i; j<=N; j +=i)
            {
                if(!arr[j])
                    arr[j] = i;
            }
        }
    }

    if(!arr[N])
        cout << N << endl;
    else
    {
        while(1)
        {
            if(!arr[N])
            {
                cout << N << endl;
                break;
            }
            cout << arr[N] << endl;
            N = N/arr[N];
        }
    }

    return 0;
}

// N이 1인경우 while문이 끝나지 않는 버그가 있음

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int M,N;
    int sum = 0;
    int min = 99999;
    bool arr[10001] = {1,1,0,};
    cin >> M >> N;

    for(int i=2; i<=sqrt(10000); i++)
    {
        if(!arr[i])
        {
            for(int j=i*i; j<=10000; j +=i)
            {
                arr[j] = true;
            }
        }
    }

    for(int i=M; i<=N; i++)
    {
        if(!arr[i])
        {
            sum  +=i;
            if(min > i)
                min = i;
        }
    }

    if(!sum)
    {
        cout << -1;
        return 0;
    }
    else 
    {
        cout << sum << endl << min;
    }

    return 0;
}
